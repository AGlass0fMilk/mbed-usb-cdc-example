/*******************************************************************************
* File Name: cycfg_routing.h
*
* Description:
* Establishes all necessary connections between hardware elements.
* This file was automatically generated and should not be modified.
* 
********************************************************************************
* Copyright 2017-2019 Cypress Semiconductor Corporation
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
********************************************************************************/

#if !defined(CYCFG_ROUTING_H)
#define CYCFG_ROUTING_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "cycfg_notices.h"
void init_cycfg_routing(void);
#define init_cycfg_connectivity() init_cycfg_routing()
#define ioss_0_port_11_pin_2_HSIOM P11_2_SMIF_SPI_SELECT0
#define ioss_0_port_11_pin_3_HSIOM P11_3_SMIF_SPI_DATA3
#define ioss_0_port_11_pin_4_HSIOM P11_4_SMIF_SPI_DATA2
#define ioss_0_port_11_pin_5_HSIOM P11_5_SMIF_SPI_DATA1
#define ioss_0_port_11_pin_6_HSIOM P11_6_SMIF_SPI_DATA0
#define ioss_0_port_11_pin_7_HSIOM P11_7_SMIF_SPI_CLK
#define ioss_0_port_13_pin_0_HSIOM P13_0_SCB6_UART_RX
#define ioss_0_port_13_pin_1_HSIOM P13_1_SCB6_UART_TX
#define ioss_0_port_1_pin_0_HSIOM HSIOM_SEL_AMUXB
#define ioss_0_port_2_pin_0_HSIOM P2_0_DSI_DSI
#define ioss_0_port_2_pin_1_HSIOM P2_1_DSI_DSI
#define ioss_0_port_2_pin_2_HSIOM P2_2_DSI_DSI
#define ioss_0_port_2_pin_3_HSIOM P2_3_DSI_DSI
#define ioss_0_port_2_pin_4_HSIOM P2_4_DSI_DSI
#define ioss_0_port_2_pin_5_HSIOM P2_5_DSI_GPIO
#define ioss_0_port_3_pin_0_HSIOM P3_0_SCB2_UART_RX
#define ioss_0_port_3_pin_1_HSIOM P3_1_SCB2_UART_TX
#define ioss_0_port_3_pin_2_HSIOM P3_2_SCB2_UART_RTS
#define ioss_0_port_3_pin_3_HSIOM P3_3_SCB2_UART_CTS
#define ioss_0_port_6_pin_0_HSIOM P6_0_SCB3_I2C_SCL
#define ioss_0_port_6_pin_1_HSIOM P6_1_SCB3_I2C_SDA
#define ioss_0_port_6_pin_4_HSIOM P6_4_CPUSS_SWJ_SWO_TDO
#define ioss_0_port_6_pin_6_HSIOM P6_6_CPUSS_SWJ_SWDIO_TMS
#define ioss_0_port_6_pin_7_HSIOM P6_7_CPUSS_SWJ_SWCLK_TCLK
#define ioss_0_port_7_pin_0_HSIOM P7_0_CPUSS_TRACE_CLOCK
#define ioss_0_port_7_pin_1_HSIOM HSIOM_SEL_AMUXB
#define ioss_0_port_7_pin_2_HSIOM HSIOM_SEL_AMUXB
#define ioss_0_port_7_pin_7_HSIOM HSIOM_SEL_AMUXB
#define ioss_0_port_8_pin_1_HSIOM HSIOM_SEL_AMUXB
#define ioss_0_port_8_pin_2_HSIOM HSIOM_SEL_AMUXB
#define ioss_0_port_8_pin_3_HSIOM HSIOM_SEL_AMUXB
#define ioss_0_port_8_pin_4_HSIOM HSIOM_SEL_AMUXB
#define ioss_0_port_8_pin_5_HSIOM HSIOM_SEL_AMUXB
#define ioss_0_port_8_pin_6_HSIOM HSIOM_SEL_AMUXB
#define ioss_0_port_8_pin_7_HSIOM HSIOM_SEL_AMUXB
#define ioss_0_port_9_pin_0_HSIOM P9_0_CPUSS_TRACE_DATA3
#define ioss_0_port_9_pin_1_HSIOM P9_1_CPUSS_TRACE_DATA2
#define ioss_0_port_9_pin_2_HSIOM P9_2_CPUSS_TRACE_DATA1
#define ioss_0_port_9_pin_3_HSIOM P9_3_CPUSS_TRACE_DATA0

#define cpuss_0_dw0_0_chan_0_tr_in_0_TRIGGER_OUT TRIG0_OUT_CPUSS_DW0_TR_IN0
#define cpuss_0_dw0_0_chan_1_tr_in_0_TRIGGER_OUT TRIG0_OUT_CPUSS_DW0_TR_IN1
#define cpuss_0_dw1_0_chan_1_tr_in_0_TRIGGER_OUT TRIG1_OUT_CPUSS_DW1_TR_IN1
#define cpuss_0_dw1_0_chan_3_tr_in_0_TRIGGER_OUT TRIG1_OUT_CPUSS_DW1_TR_IN3
#define udb_0_out_p_116_TRIGGER_IN_0 TRIG14_IN_UDB_TR_UDB0
#define udb_0_out_p_116_TRIGGER_IN_1 TRIG1_IN_TR_GROUP14_OUTPUT6
#define udb_0_out_p_117_TRIGGER_IN_0 TRIG0_IN_TR_GROUP14_OUTPUT5
#define udb_0_out_p_117_TRIGGER_IN_1 TRIG14_IN_UDB_TR_UDB1
#define udb_0_out_p_119_TRIGGER_IN_0 TRIG0_IN_TR_GROUP14_OUTPUT0
#define udb_0_out_p_119_TRIGGER_IN_1 TRIG14_IN_UDB_TR_UDB3
#define udb_0_out_p_123_TRIGGER_IN_0 TRIG14_IN_UDB_TR_UDB7
#define udb_0_out_p_123_TRIGGER_IN_1 TRIG1_IN_TR_GROUP14_OUTPUT2

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_ROUTING_H */
