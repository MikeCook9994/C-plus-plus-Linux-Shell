#ifndef COMMAND
#define COMMAND

#include "LinkedList.h"

class Command {
    private:
        int inputFD;
        const char * inFileName;
        int outputFD;
        const char * outFileName;
        char ** arguments;
        void setArgList(LinkedList<char *> * argList, int numArgs);

    public:
        Command(LinkedList<char *> * argList, int numArgs, const char * inFileName, const char * outFileName);

        ~Command();

        //int getInputFD() {return inputFD;}
        const char * getInFileName() {return inFileName;}
        int getOutputFD() {return outputFD;}
        const char * getOutFileName() {return outFileName;}
        char ** getArgList() {return arguments;}

        //void setInputFD(int fd) {inputFD = fd;}
        //void setIntputFileName(char * name) {inFileName = name;}
        void setOutputFD(int fd) {outputFD = fd;}
        //void setOutputFileName(char * name) {outFileName = name;}
};

#endif //COMMAND