all:	
	g++ shell.cpp -o LeShell -Wall -Werror

clean:
	rm -rf LeShell *.o
