#include "headers/ExecuteExternalCommand.h"

bool executeExternalCommand(char * firstArg) {

    LinkedList<char *> * tokens = new LinkedList<char *>(firstArg);

    tokenizeString(tokens);

    if(!validateCommand(tokens))
        return false;

    LinkedList<Command *> * commands = new LinkedList<Command *>();

    if(!buildCommands(tokens, commands))
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

    if(currCharType != NSC)
        return false;

    if(!currToken->getNext())
        return true;

    currToken = currToken->getNext();
    nextToken = currToken->getNext();

    while(currToken != NULL) {

        currCharType = getTokenType(currToken->getData());

        if (currCharType != NSC) {

            if(currCharType == PIPE) {

                if(pipeCount > 1 || teeCount != 0)
                    return false;

                pipeCount += 1;

                if(nextToken == NULL)
                    return false;

                nextCharType = getTokenType(nextToken->getData());
                if(nextCharType != NSC)
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
                if(nextCharType != NSC)
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
                if (nextCharType != NSC)
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
    LinkedList<char *> *arguments = new LinkedList<char *>();
    int numArgs = 0;
    int inputfd = STDIN_FILENO;
    int outputfd = STDOUT_FILENO;

    Node<char *> *currToken = tokens->getFirst();
    int currTokenType;


    while (currToken != NULL) {

        currTokenType = getTokenType(currToken->getData());

        while (currTokenType == NSC || currTokenType == REDIRECT || currTokenType == REDIRECTAPPEND) {
            if (currTokenType == NSC) {

                arguments->add(currToken->getData());
                numArgs++;

                if(currToken->getNext() == NULL) {
                    break;
                }
            }

            currToken = currToken->getNext();
            currTokenType = getTokenType(currToken->getData());
        }

        command = new Command(arguments, numArgs, inputfd, outputfd);
        commands->add(command);
        delete arguments;
        numArgs = 0;

        currToken = currToken->getNext();

    }

    return commands;

}

int getTokenType(char * token) {
    if(!strcmp("|", token))  return PIPE;
    if(!strcmp("%", token))  return TEE;
    if(!strcmp(">", token))  return REDIRECT;
    if(!strcmp(">>", token)) return REDIRECTAPPEND;
    /* does not match */     return NSC;
}

