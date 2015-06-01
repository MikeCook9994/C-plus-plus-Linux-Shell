#include "headers/defs.h"

bool executeInternalCommand(char * command) {
    if(!strcmp(command, "cd")) {
        char * path = strtok(NULL, " \t\n");
        if(path == NULL)
            path = getenv("HOME");
        if(chdir(path)) //verifies the directory changes appropriately
            return false;
        return true;
    }
    else if(!strcmp(command, "pwd")) {
        char * path = new char[MAXPATHLENGTH];
        std::cout << getcwd(path, MAXPATHLENGTH) << std::endl;
        delete path;
        return true;
    }
    else if(!strcmp(command, "exit")) {
        if(strtok(NULL, " \t\n") != NULL)
            return false;
        exit(0);
    }
    return false;
}