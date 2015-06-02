#include "headers/ExecuteExternalCommand.h"

bool executeExternalCommand(char * firstArg) {

    LinkedList<char *> * tokens = new LinkedList<char *>(firstArg);

    tokenizeString(tokens);

    if(!validateCommand(tokens))
        return false;

    LinkedList<Command *> * commands = new LinkedList<Command *>();

    if(!buildCommands(tokens, commands))
        return false;

    if(!executeCommands(commands))
        return false;

    delete tokens;

    return true;
}

void tokenizeString(LinkedList<char *> * tokens) {

    char * token;
    while((token = strtok(NULL, " \t\n"))) {
        tokens->add(token);
    }
}

bool validateCommand(LinkedList<char *> * tokens) {

    int redirectCount, redirectAppendCount, pipeCount, teeCount;
    redirectCount = redirectAppendCount = pipeCount = teeCount = 0;

    Node<char *> * currToken = tokens->getFirst();
    Node<char *> * nextToken = NULL;

    int currCharType = getTokenType(currToken->getData());
    int nextCharType;

    if(currCharType != NA)
        return false;

    if(!currToken->getNext())
        return true;

    currToken = currToken->getNext();
    nextToken = currToken->getNext();

    while(currToken != NULL) {

        currCharType = getTokenType(currToken->getData());

        if (currCharType != NA) {

            if(currCharType == PIPE) {

                if(pipeCount > 1 || teeCount != 0)
                    return false;

                pipeCount += 1;

                if(nextToken == NULL)
                    return false;

                nextCharType = getTokenType(nextToken->getData());
                if(nextCharType != NA)
                    return false;
            }

            else if(currCharType == TEE) {

                if(pipeCount != 0 || teeCount != 0)
                    return false;

                teeCount+= 1;
                pipeCount+= 2;

                if(nextToken == NULL)
                    return false;

                nextCharType = getTokenType(nextToken->getData());
                if(nextCharType != NA)
                    return false;
            }

            else if(currCharType == REDIRECT || currCharType == REDIRECTAPPEND) {

                if (redirectCount == 1 || redirectAppendCount == 1)
                    return false;

                redirectCount += 1;
                redirectAppendCount += 1;

                if (nextToken == NULL)
                    return false;

                nextCharType = getTokenType(nextToken->getData());
                if (nextCharType != NA)
                    return false;

            }
        }

        currToken = currToken->getNext();
        if(currToken != NULL)
            nextToken = currToken->getNext();
    }

    return true;
}

LinkedList<Command *> * buildCommands(LinkedList<char *> * tokens, LinkedList<Command *> * commands) {

    Command * command = NULL;
    LinkedList<char *> *arguments = NULL;
    int numArgs = 0;
    const char * inFileName = "STDIN";
    const char * outFileName = "STDOUT";

    Node<char *> * currToken = tokens->getFirst();
    int currTokenType;


    while (currToken != NULL) {

        currTokenType = getTokenType(currToken->getData());
        arguments = new LinkedList<char *>();

        while ((currTokenType == NA || currTokenType == REDIRECT || currTokenType == REDIRECTAPPEND) && currToken != NULL) {

            if (currTokenType == NA) {

                arguments->add(currToken->getData());
                numArgs++;

                if(currToken->getNext() == NULL)
                    break;
            }

            else /* if(currTokenType == REDIRECT || currTokenType == REDIRECTAPPEND) */ {
                currToken = currToken->getNext();
                outFileName = currToken->getData();
            }

            currToken = currToken->getNext();
            if(currToken != NULL)
                currTokenType = getTokenType(currToken->getData());
        }

        if(currTokenType == PIPE) {

            if(!strcmp(outFileName, "STDOUT"))
                outFileName = "PIPEWRITE";

            command = new Command(arguments, numArgs, inFileName, outFileName);
            commands->add(command);
            delete arguments;
            numArgs = 0;

            outFileName = "STDOUT";
            inFileName = "PIPEREAD";

        }

        else if(currTokenType == TEE) {

            if(!strcmp(outFileName, "STDOUT"))
                outFileName = "PIPEWRITE";

            command = new Command(arguments, numArgs, inFileName, outFileName);
            commands->add(command);
            delete arguments;
            numArgs = 0;

            //handles the creation of the my tee command
            outFileName = "mytee.txt";
            inFileName = "PIPEREAD";
            arguments = new LinkedList<char *>((char *)"mytee");
            numArgs++;

            command = new Command(arguments, numArgs, inFileName, outFileName);
            commands->add(command);
            delete arguments;
            numArgs = 0;

            outFileName = "STDOUT";
            inFileName = "mytee.txt";

        }

        else /* if(currToken->getNext() == NULL) <- This denotes the end of the input string */ {

            command = new Command(arguments, numArgs, inFileName, outFileName);
            commands->add(command);
            delete arguments;
            return commands;
        }

        currToken = currToken->getNext();
    }

    return commands;
}

bool executeCommands(LinkedList<Command *> * commands) {
        return true;
}

int getTokenType(char * token) {
    if(!strcmp("|", token))  return PIPE;
    if(!strcmp("%", token))  return TEE;
    if(!strcmp(">", token))  return REDIRECT;
    if(!strcmp(">>", token)) return REDIRECTAPPEND;
    /* does not match */     return NA;
}

