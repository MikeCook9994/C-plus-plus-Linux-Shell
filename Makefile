all:	
	g++ Shell.cpp ExecuteInternalCommand.cpp ExecuteExternalCommand.cpp Command.cpp -o LeShell -g -Wall -Werror

clean:
	rm -rf LeShell *.o
