#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXCOMMANDLENGTH 1024

bool handleShellOperation(char * token);

int main(int charc, char *argv[]) {

    char * command, * token;

    for(;;) {
        std::cout << "ᕕ( ᐛ )ᕗ"; //prints the console prompt

        command = (char *)malloc(sizeof(char) * MAXCOMMANDLENGTH);
        fgets(command, 1024, stdin); // gets the command
        strtok(command, "\n\0"); //strips the newline and null character off the command"

        token = (char *)strtok(command, " \t");

        if( !strcmp(token, "cd") || !strcmp(token, "pwd") || !strcmp(token, "exit")) {
            if(!handleShellOperation(token)) {
                std::cerr << "Error!" << std::endl;
                exit(0);
            }
            else {

            }
        }

        free(command);
    }

    return 0;
}

bool handleShellOperation(char * token) {
    if(!strcmp(token, "cd")) {
        char * path = strtok(NULL, " \t");
        if(path == NULL)
            path = getenv("HOME");
            chdir(path);
        return true;
    }
    else if(!strcmp(token, "pwd")) {
        char * path = (char *)malloc(sizeof(char) * MAXCOMMANDLENGTH);
        std::cout << getcwd(path, MAXCOMMANDLENGTH) << std::endl;
        return true;
    }
    else if(!strcmp(token, "exit")) {
        exit(0);
    }
    return false;
}


