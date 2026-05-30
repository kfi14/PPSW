#include <LPC21xx.H>
#include "string.h"


#define NULL '\0'


enum CompResult eCompareString(char pcStr1[], char pcStr2[]) {
    unsigned char ucCharacterCounter;
    for (ucCharacterCounter = 0; (pcStr1[ucCharacterCounter] != NULL) || (pcStr2[ucCharacterCounter] != NULL); ucCharacterCounter++) {
        if (pcStr1[ucCharacterCounter] != pcStr2[ucCharacterCounter]) {
            return DIFFERENT;
        }
    }
    return EQUAL;
}


enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue) {
    unsigned char ucCharacterCounter;
    unsigned char ucCurrentCharacter;
    unsigned int uiLocalValue = 0;

    if((pcStr[0] != '0') || (pcStr[1] != 'x') || (pcStr[2] == NULL)) {
        return ERROR;
    }

    for(ucCharacterCounter = 2; pcStr[ucCharacterCounter] != NULL ; ucCharacterCounter++) {
        ucCurrentCharacter = pcStr[ucCharacterCounter];

        if (ucCharacterCounter == 6) {
            return ERROR;
        }

        uiLocalValue = uiLocalValue << 4; 

        if((ucCurrentCharacter <= '9') && (ucCurrentCharacter >= '0')) {
            uiLocalValue = uiLocalValue | (ucCurrentCharacter - '0');
        }
        else if((ucCurrentCharacter <= 'F') && (ucCurrentCharacter >= 'A')) {
            uiLocalValue = uiLocalValue | (ucCurrentCharacter - 'A' + 10);
        }
        else {
            return ERROR;
        }
    }

    *puiValue = uiLocalValue; 
    return OK;
}



void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar){

    unsigned char ucCharacterCounter;

    for(ucCharacterCounter = 0 ; pcString[ucCharacterCounter] != NULL; ucCharacterCounter++)
    {
        if(pcString[ucCharacterCounter] == cOldChar)
        {
            pcString[ucCharacterCounter] = cNewChar;
        }
    }
}

void CopyString(char pcSource[], char pcDestination[])
{
    
    unsigned char ucCharacterCounter;
    
    for(ucCharacterCounter = 0 ; pcSource[ucCharacterCounter] != NULL ; ucCharacterCounter++)
    {
        pcDestination[ucCharacterCounter] = pcSource[ucCharacterCounter];
    }
    pcDestination[ucCharacterCounter] = NULL;
}

