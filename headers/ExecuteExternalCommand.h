#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "defs.h"
#include "LinkedList.h"
#include "Command.h"

typedef enum TokenType {
    NA = 0, //Non-Special Character: Denotes that the character is not one of the 4 special IO modifying characters
    PIPE = 1,
    TEE = 2,
    REDIRECT = 3,
    REDIRECTAPPEND = 4
} TokenType;

void tokenizeString(LinkedList<char *> * tokens);
bool validateCommand(LinkedList<char *> * tokens);
LinkedList<Command *> * buildCommands(LinkedList<char *> * tokens, LinkedList<Command *> * commands);
bool executeCommands(LinkedList<Command *> * commands);
int getTokenType(char * token);
