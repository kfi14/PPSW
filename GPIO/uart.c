#include <LPC210X.H>
#include "uart.h"

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


/************ Interrupts **********/
// VIC (Vector Interrupt Controller) channels
#define VIC_UART0_CHANNEL_NR  6
#define VIC_UART1_CHANNEL_NR  7

// VICVectCntlx Vector Control Registers
#define mIRQ_SLOT_ENABLE                           0x00000020


/************ Decoding**********/
#define RECIEVER_SIZE 														7
#define TERMINATOR 																' '
#define NULL                                      '\0'

////////////// Zmienne globalne ////////////
char cOdebranyZnak;


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
      // narazie nic nie wysylamy
   }

   VICVectAddr = 0; // Acknowledge Interrupt
}

////////////////////////////////////////////
void UART_InitWithInt(unsigned int uiBaudRate){

   // UART0
   PINSEL0 = PINSEL0 | mP01_AS_UART0_RxD;                        // ustawic pina na odbiornik uart0
   U0LCR  |= m8BIT_UART_WORD_LENGTH | mDIVISOR_LATCH_ACCES_BIT; // dlugosc slowa, DLAB = 1
   U0DLL   = (((15000000)/16)/uiBaudRate);                      // predkosc transmisji
   U0LCR  &= (~mDIVISOR_LATCH_ACCES_BIT);                       // DLAB = 0
   U0IER  |= mRX_DATA_AVALIABLE_INTERRUPT_ENABLE;               // wlaczenie przewan od odbiornika

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
	
	for(sBuffer.ucCharCtr = 0; sBuffer.cData[sBuffer.ucCharCtr] != NULL; sBuffer.ucCharCtr++){
		ucDestination[sBuffer.ucCharCtr] = sBuffer.cData[sBuffer.ucCharCtr];
	}
	
	ucDestination[sBuffer.ucCharCtr] = NULL;
	sBuffer.ucCharCtr = 0;
	sBuffer.eStatus = EMPTY;
}

enum CompResult eCompareString(char pcStr1[], char pcStr2[]) {
    unsigned char ucCharacterCounter;
    for (ucCharacterCounter = 0; (pcStr1[ucCharacterCounter] != NULL) || (pcStr2[ucCharacterCounter] != NULL); ucCharacterCounter++) {
        if (pcStr1[ucCharacterCounter] != pcStr2[ucCharacterCounter]) {
            return DIFFERENT;
        }
    }
    return EQUAL;
}