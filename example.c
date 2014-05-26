#define RING_BUFFER_SIZE 128
#define BAUD 19200

#include "ring_buffer.h"
#include "uart_avr.h"
rBuffer txBuffer, rxBuffer;

void main() {
	uart_init(BAUD);
	ringFlush(&txBuffer);
	ringFlush(&rxBuffer);
	ringWriteData(&txBuffer, "HelloWorld");
	uart_send(&txBuffer);
	while(1);
}