#ifndef SHELL_DEFS
#define SHELL_DEFS

//includes
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//definitions
#define MAXCOMMANDLENGTH 1024

//ExecuteInlineCommand Function Prototypes
bool executeInternalCommand(char * command);

//ExecuteExternalCommand Function Prototypes
bool executeExternalCommand(char * command);

#endif //SHELL_DEFS
