#include "defs.h"
#include "LinkedList.h"

typedef enum TokenType {
    NSC = 0,
    PIPE = 1,
    TEE = 2,
    REDIRECT = 3,
    REDIRECTAPPEND = 4
} TokenType ;

void tokenizeString(LinkedList<char *> * tokens);
bool validateCommand(LinkedList<char *> * tokens);
int isSpecialChar(char *);
