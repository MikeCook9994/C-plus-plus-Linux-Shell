#ifndef COMMAND
#define COMMAND

#include "LinkedList.h"

class Command {
    private:
        int inputFD;
        int outputFD;
        char ** arguments;
        void setArgList(LinkedList<char *> * argList, int numArgs);

    public:
        Command(LinkedList<char *> * argList, int numArgs, int infd, int outfd);

        ~Command();

        int getInputFD() {return inputFD;}
        int getOutputFD() {return outputFD;}
        char ** getArgList() {return arguments;}

        void setInputFD(int fd) {inputFD = fd;}
        void setOutputFD(int fd) {outputFD = fd;}
};

#endif //COMMAND