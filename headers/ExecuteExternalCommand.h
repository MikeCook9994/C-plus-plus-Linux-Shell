#include <fcntl.h>
#include "defs.h"
#include "LinkedList.h"
#include "Command.h"

typedef enum TokenType {
    NSC = 0, //Non-Special Character: Denotes that the character is not one of the 4 special IO modifying characters
    PIPE = 1,
    TEE = 2,
    REDIRECT = 3,
    REDIRECTAPPEND = 4
} TokenType;

void tokenizeString(LinkedList<char *> * tokens);
bool validateCommand(LinkedList<char *> * tokens);
int getTokenType(char * token);
LinkedList<Command *> * buildCommands(LinkedList<char *> * tokens, LinkedList<Command *> * commands);
