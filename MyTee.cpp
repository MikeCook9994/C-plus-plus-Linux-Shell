#include <iostream>
#include <errno.h>

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int charc, char *argv[]) {

    int teefd;
    char input[1];

    if((teefd = open("tee.txt", O_CREAT | O_TRUNC | O_RDWR, S_IWUSR | S_IRUSR)) == -1)
        return -1;

    std::cerr << teefd << std::endl;

    while(read(STDIN_FILENO, input, 1)) {
        if(write(STDOUT_FILENO, input, 1) != 1)
            return -1;

        if(write(teefd, input, 1) < 0)
            return -1;
    }

    close(teefd);

    return 0;
}
