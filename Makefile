all:	
	g++ Shell.cpp ExecuteInternalCommand.cpp ExecuteExternalCommand.cpp Command.cpp -o LeShell -Wall -Werror
	g++ MyTee.cpp -o mytee -Wall -Werror

clean:
	rm -rf LeShell mytee *.o
