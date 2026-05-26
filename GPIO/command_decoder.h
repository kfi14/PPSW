#define MAX_TOKEN_NR 															3 

enum KeywordCode {CLB, GT};
enum TokenType {KEYWORD, NUMBER, STRING};
void DecodeMsg(char *pcString);

union TokenValue{
	enum KeywordCode eKeyword;
	unsigned int uiValue;
	char* pcString;
};

struct Token {
enum TokenType eType; 
union TokenValue uValue;
};
extern struct Token asToken[MAX_TOKEN_NR];
extern unsigned char ucTokenNr;

