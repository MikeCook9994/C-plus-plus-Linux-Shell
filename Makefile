all:	
	g++ shell.cpp ParseCommandLine.cpp -o LeShell -Wall -Werror

clean:
	rm -rf LeShell *.o
