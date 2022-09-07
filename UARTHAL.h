#ifndef UARTHAL_H_
#define UARTHAL_H_



typedef void(*receiverCharInterrupt)(char c);

typedef struct {
	void(*write)(char *buffer, int bufferSize);
	void(*setReceiverCharInterrupt)(receiverCharInterrupt interrupt);
} UARTHAL;


#endif
