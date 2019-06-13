/* Copyright (c) 2017-2018 ARM Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


/* -------------------------------------- Includes ----------------------------------- */

#include "spm_api.h"
#include "device.h"
#include "cyip_ipc.h"
#include "cy_ipc_drv.h"
#include "cy_syslib.h"
#include "cy_sysint.h"
#include "psoc6_utils.h"
#include "mbed_error.h"

#if (CY_CPU_CORTEX_M0P)
	#include "device.h"
	#include "psoc6_utils.h"
	#include "mbed_error.h"
#endif /* (CY_CPU_CORTEX_M0P) */



/* ------------------------------------ Definitions ---------------------------------- */

#define SPM_IPC_CHANNEL 8u
#define SPM_IPC_NOTIFY_CM0P_INTR    (CY_IPC_INTR_SPARE + 2) // CM4 to CM0+ notify interrupt number
#define SPM_IPC_NOTIFY_CM4_INTR     (CY_IPC_INTR_SPARE + 1) // CM0+ to CM4 notify interrupt number



/* ---------------------------------- Static Globals --------------------------------- */

static IPC_STRUCT_Type      *ipc_channel_handle;
static IPC_INTR_STRUCT_Type *ipc_interrupt_ptr;



/* ------------------------ Platform's Functions Implementation ---------------------- */

void ipc_interrupt_handler(void)
{
    // Call ARM's interrupt handler
    spm_mailbox_irq_callback();

    // Clear the interrupt and make a dummy read to avoid double interrupt occurrence:
    // - The double interrupt’s triggering is caused by buffered write operations on bus
    // - The dummy read of the status register is indeed required to make sure previous write completed before leaving ISR
    // Note: This is a direct clear using the IPC interrupt register and not clear of an NVIC register
    Cy_IPC_Drv_ClearInterrupt(ipc_interrupt_ptr, CY_IPC_NO_NOTIFICATION, (1uL << SPM_IPC_CHANNEL));
}

void mailbox_init(void)
{
    // Interrupts configuration
    // * See ce216795_common.h for occupied interrupts
    // -----------------------------------------------

    // Configure interrupts ISR / MUX and priority
    cy_stc_sysint_t ipc_intr_Config;
	
#if (CY_CPU_CORTEX_M4)
	ipc_intr_Config.intrSrc = (IRQn_Type)cpuss_interrupts_ipc_0_IRQn + SPM_IPC_NOTIFY_CM4_INTR;
    ipc_intr_Config.intrPriority = 1;
#else
	ipc_intr_Config.intrSrc = CY_M0_CORE_IRQ_CHANNEL_PSA_MAILBOX;
    ipc_intr_Config.cm0pSrc = (cy_en_intr_t)cpuss_interrupts_ipc_0_IRQn + SPM_IPC_NOTIFY_CM0P_INTR;    // Must match the interrupt we trigger using NOTIFY on CM4
    ipc_intr_Config.intrPriority = 1;
    if (cy_m0_nvic_reserve_channel(CY_M0_CORE_IRQ_CHANNEL_PSA_MAILBOX, CY_PSA_MAILBOX_IRQN_ID) == (IRQn_Type)(-1)) {
        error("PSA SPM Mailbox NVIC channel reservation conflict.");
    }
#endif /* (CY_CPU_CORTEX_M4) */
	
    (void)Cy_SysInt_Init(&ipc_intr_Config, ipc_interrupt_handler);

    // Set specific NOTIFY interrupt mask only.
    // Only the interrupt sources with their masks enabled can trigger the interrupt.
#if (CY_CPU_CORTEX_M4)
    ipc_interrupt_ptr = Cy_IPC_Drv_GetIntrBaseAddr(SPM_IPC_NOTIFY_CM4_INTR);
#else
    ipc_interrupt_ptr = Cy_IPC_Drv_GetIntrBaseAddr(SPM_IPC_NOTIFY_CM0P_INTR);
#endif /* (CY_CPU_CORTEX_M4) */
    CY_ASSERT(ipc_interrupt_ptr != NULL);
    Cy_IPC_Drv_SetInterruptMask(ipc_interrupt_ptr, 0x0, 1 << SPM_IPC_CHANNEL);

    // Enable the interrupt
    NVIC_EnableIRQ(ipc_intr_Config.intrSrc);

    ipc_channel_handle = Cy_IPC_Drv_GetIpcBaseAddress(SPM_IPC_CHANNEL);
    CY_ASSERT(ipc_channel_handle != NULL);
}



/* -------------------------------------- HAL API ------------------------------------ */

void spm_hal_mailbox_notify(void)
{
    CY_ASSERT(ipc_channel_handle != NULL);
#if (CY_CPU_CORTEX_M4)
    Cy_IPC_Drv_AcquireNotify(ipc_channel_handle, (1uL << SPM_IPC_NOTIFY_CM0P_INTR));
#else
	Cy_IPC_Drv_AcquireNotify(ipc_channel_handle, (1uL << SPM_IPC_NOTIFY_CM4_INTR));
#endif /* (CY_CPU_CORTEX_M4) */
}
