all:	
	g++ Shell.cpp ExecuteInternalCommand.cpp ExecuteExternalCommand.cpp Command.cpp -o LeShell -Wall -Werror

clean:
	rm -rf LeShell *.o
