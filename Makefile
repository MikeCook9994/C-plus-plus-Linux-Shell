all:	
	g++ Shell.cpp ExecuteInternalCommand.cpp ExecuteExternalCommand.cpp -o LeShell -Wall -Werror

clean:
	rm -rf LeShell *.o
