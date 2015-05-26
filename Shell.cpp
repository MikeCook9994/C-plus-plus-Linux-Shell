#include "defs.h"

int main(int charc, char *argv[]) {

    char * command, * token;

    for(;;) {
        std::cout << "ᕕ( ᐛ )ᕗ"; //prints the console prompt

        command = new char[MAXCOMMANDLENGTH];
        fgets(command, MAXCOMMANDLENGTH, stdin); // gets the command

        token = (char *)strtok(command, " \t\n");
        if(!token)
            continue;

        if(!strcmp(token, "cd") || !strcmp(token, "pwd") || !strcmp(token, "exit")) {
            if(!executeInternalCommand(token)) {
                std::cerr << "Error!" << std::endl;
            }
        }
        else if(!executeExternalCommand(token)) {
            std::cerr << "Error!" << std::endl;
        }

        free(command);
    }

    return 0;
}


