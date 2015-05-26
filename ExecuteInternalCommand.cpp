#include "defs.h"

bool executeInternalCommand(char * command) {
    if(!strcmp(command, "cd")) {
        char * path = strtok(NULL, " \t\n");
        if(path == NULL)
            path = getenv("HOME");
        chdir(path);
        return true;
    }
    else if(!strcmp(command, "pwd")) {
        char * path = new char[MAXCOMMANDLENGTH];
        std::cout << getcwd(path, MAXCOMMANDLENGTH) << std::endl;
        delete path;
        return true;
    }
    else if(!strcmp(command, "exit")) {
        exit(0);
    }
    return false;
}