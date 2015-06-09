all:	
	g++ Shell.cpp ExecuteInternalCommand.cpp ExecuteExternalCommand.cpp Command.cpp -o LeShell -Wall -Werror

debug:
	g++ Shell.cpp ExecuteInternalCommand.cpp ExecuteExternalCommand.cpp Command.cpp -o LeShell -g

clean:
	rm -rf LeShell *.o
