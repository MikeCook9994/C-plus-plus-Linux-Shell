#include "ExecuteExternalCommand.h"

bool executeExternalCommand(char * command) {

    LinkedList<char *> * tokens = new LinkedList<char *>(command);
    tokenizeString(tokens);

    return true;
}

void tokenizeString(LinkedList<char *> * tokens) {
    char * token;
    while((token = strtok(NULL, " \t\n"))) {
        tokens->add(token);
    }
}