#include "headers/Command.h"

Command::Command(LinkedList<char *> * argList, int numArgs, const char * ifn, const char * ofn) {
    inFileName = ifn;
    inputFD = STDIN_FILENO;
    outFileName = ofn;
    outputFD = STDOUT_FILENO;
    arguments = (char **)malloc(sizeof(char *) * numArgs);
    setArgList(argList, numArgs);
}

Command::~Command() {
    free(arguments);
}

void Command::setArgList(LinkedList<char *> * args, int numArgs) {

    Node<char *> * currArg = args->getFirst();

    for(int i = 0; i < numArgs; i++) {
        arguments[i] = currArg->getData();
        currArg = currArg->getNext();
    }

}