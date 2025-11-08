#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024


int main(){
    char path_1[256];
    printf("Please enter the firts path\n");
    scanf("%255s", path_1);

    char path_2[256];
    printf("Please enter the second path\n");
    scanf("%255s", path_2);

    int fd_1 = open (path_1, O_RDONLY);

    if(fd_1 == -1) {
        perror("Error opening first file");
        return 1;
    }

    int fd_2 = open (path_2, O_RDONLY);

    if(fd_2 == -1) {
        perror("Error opening second file");
        return 1;
    }
    char buffer_1[BUF_SIZE];
    char buffer_2[BUF_SIZE];
    off_t offset = 0;


    while(1) {

        ssize_t bytes1 = read(fd_1, buffer_1, BUF_SIZE);
        if(bytes1 == -1) {
            perror("Error reading first file");
            close(fd_1);
            close(fd_2);
            return 1;
        }   
        
        ssize_t bytes2 = read(fd_2, buffer_2, BUF_SIZE);
        if(bytes2 == -1) {
            perror("Error reading second file");
            close(fd_1);
            close(fd_2);
            return 1;
        }   

        if(bytes1 == 0 && bytes2 == 0) {
            printf("Files are identical\n");
            close(fd_1);
            close(fd_2);
            break;
        }

        size_t min = bytes1 < bytes2 ? bytes1 : bytes2;

        for(size_t i = 0; i < min; i++) {
            if(buffer_1[i] != buffer_2[i]) {
                printf("Files are different at %lu\n", offset+i);
                close(fd_1);
                close(fd_2);
                return 0;
            }
        }

        if (bytes1 != bytes2) {
            printf("Files differ at byte %lu\n", offset + min);
            close(fd_1);
            close(fd_2);
            return 0;
        }

        offset += bytes1;
    }
}
