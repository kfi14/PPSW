#define NULL '\0'
#define NIBBLE_MASK 0x000F
#define NIBBLES_IN_UI 4

void UIntToHexStr(unsigned int uiValue, char pcStr[]){
	
	unsigned char ucNibbleCounter;
	unsigned char ucCurrentNibble;
	
	pcStr[0] = '0';
	pcStr[1] = 'x';
	pcStr[6] = NULL;
	
	for(ucNibbleCounter = 0; ucNibbleCounter < NIBBLES_IN_UI; ucNibbleCounter++){
		
		ucCurrentNibble = ((uiValue >> (ucNibbleCounter * NIBBLES_IN_UI) ) & NIBBLE_MASK);
		
		if(ucCurrentNibble < 10){
			pcStr[5 - ucNibbleCounter] = ucCurrentNibble + '0';
		}
		else{
			pcStr[5-ucNibbleCounter] = (ucCurrentNibble-10) + 'A';
		}
	}
}

enum Result {OK, ERROR};

enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue){
	
	unsigned char ucCharCounter;
	unsigned char ucCurrentChar;
	
	if('0' != pcStr[0] | 'x' != pcStr[1] | NULL == pcStr[2]){
		return ERROR;
	}
	
	*puiValue = 0;
	
	for(ucCharCounter = 2; pcStr[ucCharCounter] != NULL; ucCharCounter++){
		
		ucCurrentChar = pcStr[ucCharCounter];
		
		if(6 == ucCharCounter){
			return ERROR;
		}
		
		*puiValue = *puiValue << 4;
		
		if(('0' <= ucCurrentChar) && ('9' >= ucCurrentChar)){
			*puiValue = *puiValue | (ucCurrentChar - '0');
		}
		else if(('A' <= ucCurrentChar) && ('F' >= ucCurrentChar)){
			*puiValue = *puiValue | (ucCurrentChar - 'A' + 10);
		}
		else{
			return ERROR;
		}
	}
	return OK;
}

void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[]){
	
	unsigned char ucCharCounter;
	
	for(ucCharCounter = 0; pcDestinationStr[ucCharCounter] != NULL; ucCharCounter++){}
	
	UIntToHexStr(uiValue, &pcDestinationStr[ucCharCounter]);

	}
		










enum Result eStatus;
char cHexString[] = "0xABC9";
char cErrorString[] = "test";
unsigned int uiValue;

int main(void){
	
		eStatus = eHexStringToUInt(cHexString, &uiValue);
	
		eStatus = eHexStringToUInt(cErrorString, &uiValue);
			
}
	