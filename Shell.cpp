#include "headers/defs.h"

int main(int charc, char *argv[]) {

    char * command, * token;

    for(;;) {
        std::cout << "ᕕ( ᐛ )ᕗ "; //prints the console prompt

        command = new char[MAXCOMMANDLENGTH];
        if(!fgets(command, MAXCOMMANDLENGTH, stdin)) {
            error();
            delete command;
            continue;
        }

        token = strtok(command, " \t\n");
        if(!token) {
            delete command;
            continue;
        }

        if(!strcmp(token, "cd") || !strcmp(token, "pwd") || !strcmp(token, "exit")) {
            if(!executeInternalCommand(token))
                error();
        }
        else if(!executeExternalCommand(token))
            error();

        delete command;
    }

    return 0;
}

void error(void) {
    std::cout << "Error!" << std::endl;
}

