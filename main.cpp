#include <mbed.h>
#include <USBSerial.h>

USBSerial serial;
DigitalOut LedB(P0_12, 1);
volatile uint32_t milliseconds;
Ticker ticker;

void global_timer_IRQ(void)
{
  milliseconds += 1;
}

int main(void)
{
  milliseconds = 0;
  ticker.attach_us(global_timer_IRQ, 1000); // Comment this line to unfreeze
  while (1)
  {
    LedB.write(0);
    wait(1);
    LedB.write(1);

    serial.printf("us_ticker:%d, milliseconds:%d\n", (int) us_ticker_read(), (int) milliseconds);

    wait(1);
  }
}
