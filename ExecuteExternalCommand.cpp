#include "ExecuteExternalCommand.h"

bool executeExternalCommand(char * command) {

    LinkedList<char *> * tokens = new LinkedList<char *>(command);

    tokenizeString(tokens);

    if(!validateCommand(tokens))
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

    Node<char *> * currToken = tokens->getHeadNode();
    Node<char *> * nextToken = currToken->getNext();

    int currCharType = isSpecialChar(currToken->getData());
    int nextCharType;

    if(currCharType != NSC)
        return false;

    if(!currToken->getNext())
        return true;

    currToken = currToken->getNext();
    nextToken = currToken->getNext();

    while(currToken != NULL) {

        currCharType = isSpecialChar(currToken->getData());

        if (currCharType != NSC) {

            if(currCharType == PIPE) {

                if(pipeCount > 1 || teeCount != 0)
                    return false;

                pipeCount += 1;

                if(nextToken == NULL)
                    return false;

                nextCharType = isSpecialChar(nextToken->getData());
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

                nextCharType = isSpecialChar(nextToken->getData());
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

                nextCharType = isSpecialChar(nextToken->getData());
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

int isSpecialChar(char * token) {
    if(!strcmp("|", token))  return PIPE;
    if(!strcmp("%", token))  return TEE;
    if(!strcmp(">", token))  return REDIRECT;
    if(!strcmp(">>", token)) return REDIRECTAPPEND;
    /* does not match */     return NSC;
}