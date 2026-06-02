enum CompResult {DIFFERENT, EQUAL};
enum CompResult eCompareString(char pcStr1[], char pcStr2[]);
enum Result {OK, ERROR};
enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue);
void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar);
void CopyString(char pcSource[], char pcDestination[]);
void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[]);