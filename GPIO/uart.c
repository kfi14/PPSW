#include <LPC210X.H>
#include "uart.h"
#include "string.h"


/************ UART ************/
// U0LCR Line Control Register
#define mDIVISOR_LATCH_ACCES_BIT                   0x00000080
#define m8BIT_UART_WORD_LENGTH                     0x00000003

// UxIER Interrupt Enable Register
#define mRX_DATA_AVALIABLE_INTERRUPT_ENABLE        0x00000001
#define mTHRE_INTERRUPT_ENABLE                     0x00000002

// UxIIR Pending Interrupt Identification Register
#define mINTERRUPT_PENDING_IDETIFICATION_BITFIELD  0x0000000F
#define mTHRE_INTERRUPT_PENDING                    0x00000002
#define mRX_DATA_AVALIABLE_INTERRUPT_PENDING       0x00000004

// Pin Function Select Register
#define mP01_AS_UART0_RxD                          0x00000004
#define mP01_AS_UART_TxD													 0x00000001


/************ Interrupts **********/
// VIC (Vector Interrupt Controller) channels
#define VIC_UART0_CHANNEL_NR  6
#define VIC_UART1_CHANNEL_NR  7

// VICVectCntlx Vector Control Registers
#define mIRQ_SLOT_ENABLE                           0x00000020


////////////// Zmienne globalne ////////////
char cOdebranyZnak;
char cWyslanyZnak;

/************ Buffer **********/
// RECIEVER
#define RECIEVER_SIZE 														12
#define TERMINATOR 																'\r'
#define NULL 																			'\0'
// TRANSMITTER
#define TRANSMITER_SIZE													8

///////////////////////////////////////////
__irq void UART0_Interrupt (void) {
   // jesli przerwanie z odbiornika (Rx)
   
   unsigned int uiCopyOfU0IIR=U0IIR; // odczyt U0IIR powoduje jego kasowanie wiec lepiej pracowac na kopii

   if      ((uiCopyOfU0IIR & mINTERRUPT_PENDING_IDETIFICATION_BITFIELD) == mRX_DATA_AVALIABLE_INTERRUPT_PENDING) // odebrano znak
   {
      cOdebranyZnak = U0RBR;
			Reciever_PutCharacterToBuffer(cOdebranyZnak);
   } 
   
   if ((uiCopyOfU0IIR & mINTERRUPT_PENDING_IDETIFICATION_BITFIELD) == mTHRE_INTERRUPT_PENDING)              // wyslano znak - nadajnik pusty 
   {
      cWyslanyZnak++;
			U0THR = Transmiter_GetCharacterFromBuffer();
		 
   }

   VICVectAddr = 0; // Acknowledge Interrupt
}

////////////////////////////////////////////
void UART_InitWithInt(unsigned int uiBaudRate){

   // UART0
   PINSEL0 = PINSEL0 | mP01_AS_UART0_RxD | mP01_AS_UART_TxD;   // ustawic pina na odbiornik uart0
   U0LCR  |= m8BIT_UART_WORD_LENGTH | mDIVISOR_LATCH_ACCES_BIT; // dlugosc slowa, DLAB = 1
   U0DLL   = (((15000000)/16)/uiBaudRate);                      // predkosc transmisji
   U0LCR  &= (~mDIVISOR_LATCH_ACCES_BIT);                       // DLAB = 0
   U0IER  |= mRX_DATA_AVALIABLE_INTERRUPT_ENABLE | mTHRE_INTERRUPT_ENABLE;               // wlaczenie przewan od odbiornika

   // INT
   VICVectAddr1  = (unsigned long) UART0_Interrupt;             // set interrupt service routine address
   VICVectCntl1  = mIRQ_SLOT_ENABLE | VIC_UART0_CHANNEL_NR;     // use it for UART 0 Interrupt
   VICIntEnable |= (0x1 << VIC_UART0_CHANNEL_NR);               // Enable UART 0 Interrupt Channel
}


struct RecieverBuffer{ 
	char cData[RECIEVER_SIZE];
	unsigned char ucCharCtr;
	enum eRecieverStatus eStatus;
};
struct RecieverBuffer sBuffer;

void Reciever_PutCharacterToBuffer(char cCharacter){

	if(cCharacter == TERMINATOR && sBuffer.ucCharCtr <= RECIEVER_SIZE ){
		sBuffer.cData[sBuffer.ucCharCtr] = NULL;
		sBuffer.eStatus = READY;
		sBuffer.ucCharCtr = 0;
	}
	else if(sBuffer.ucCharCtr >= RECIEVER_SIZE){
		sBuffer.eStatus = OVERFLOW;
	}
	else{
	  sBuffer.cData[sBuffer.ucCharCtr] = cCharacter;
		sBuffer.ucCharCtr++;
	}
}

enum eRecieverStatus eReciever_GetStatus(void){
	
	return sBuffer.eStatus;
}

void Reciever_GetStringCopy(char * ucDestination){
	
	CopyString(sBuffer.cData, ucDestination);
	sBuffer.ucCharCtr = 0;
	sBuffer.eStatus = EMPTY;
}


  
struct TransmiterBuffer{ 
char cData[TRANSMITER_SIZE];   
enum     eTransmiterStatus eStatus;  
unsigned char fLastCharacter;  
unsigned char cCharCtr;  
};   
struct TransmiterBuffer sTransmiterBuffer;  



char Transmiter_GetCharacterFromBuffer() {
	static char cTransmitChar;
	
	if((NULL != sTransmiterBuffer.cData[sTransmiterBuffer.cCharCtr]) && (0 == sTransmiterBuffer.fLastCharacter)) {
		
		cTransmitChar = sTransmiterBuffer.cData[sTransmiterBuffer.cCharCtr];
		sTransmiterBuffer.cCharCtr++;
		return cTransmitChar;
	} else if ((NULL == sTransmiterBuffer.cData[sTransmiterBuffer.cCharCtr]) && (0 == sTransmiterBuffer.fLastCharacter)){
		
		sTransmiterBuffer.fLastCharacter = 1; 
		return TERMINATOR;
	}	else if ((NULL == sTransmiterBuffer.cData[sTransmiterBuffer.cCharCtr]) && (1 == sTransmiterBuffer.fLastCharacter)){
		
		sTransmiterBuffer.cCharCtr = 0;
		sTransmiterBuffer.fLastCharacter = 0; 
		sTransmiterBuffer.eStatus = FREE;
		
		return NULL;
	}
	
	return NULL;
}



void Transmiter_SendString(char cString[]){
	CopyString(cString, sTransmiterBuffer.cData);
	U0THR = sTransmiterBuffer.cData[0];
	sTransmiterBuffer.eStatus = BUSY;
	sTransmiterBuffer.cCharCtr=1;
}


enum eTransmiterStatus Transmiter_GetStatus(void){
	return sTransmiterBuffer.eStatus;
}



