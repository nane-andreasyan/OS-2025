#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>


#define FILENAME "numbers.txt"

int main() {
    int fd = open (FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error opening log file");
        return 1;
    }

    for(int i = 1; i <= 10; i++) {
        char buffer[16];
        int len = snprintf(buffer, sizeof(buffer), "%d\n", i);
        if(len < 0) {
            perror("Error formatting number string");
            close(fd);
            return 1;
        }
        ssize_t bytes_written = write(fd, buffer, len);
        if(bytes_written == -1) { 
            perror("Error writing to file");
            close (fd);
            return 1;
        }
    }
    close(fd);

    int fd_2 = open (FILENAME, O_RDWR, 0644);
    if (fd_2 == -1)
    {
        perror("Error opening log file");
        return 1;
    }

    int count = 0;
    off_t pos;
    off_t end_pos;
    char c;
    
    while (1) {
        ssize_t n = read(fd_2, &c, 1);
        if(c == '\n') {
            count++;
            if(count == 3) {
                pos = lseek(fd_2, 0, SEEK_CUR);
                if(pos == -1) {
                    perror("Error seeking in file");
                    close(fd_2);
                    return 1;
                }
            }
            if(count == 4){
                end_pos = lseek(fd_2, 0, SEEK_CUR);
                    if(end_pos == -1) {
                        perror("Error seeking in file");
                        close(fd_2);
                        return 1;
                    }
                break;
            }
        }
    }
    off_t change_pos = lseek(fd_2, pos, SEEK_SET);
    if(change_pos == -1) {
        perror("Error seeking in file");
        close(fd_2);
        return 1;
    }

    off_t file_size = lseek(fd_2, 0, SEEK_END);
    if(file_size == -1) {
        perror("Error seeking size");
        close(fd_2);
        return 1;
    }


    off_t remaining = file_size-end_pos;
    char *buffer = malloc(remaining);
    if(!buffer) {
        perror("Error allocating memory");
        close(fd_2);
        return 1;   
    }

    off_t start = lseek(fd_2, end_pos, SEEK_SET);
    if(start == -1) {
        perror("Error seeking in file");
        free(buffer);
        buffer = NULL;
        close(fd_2);
        return 1;   
    }

    ssize_t bytes_read = read(fd_2, buffer, remaining);
    if(bytes_read == -1) {
        perror("Error reading file");
        free(buffer);
        buffer = NULL;
        close(fd_2);
        return 1;   
    }

    start = lseek(fd_2, pos, SEEK_SET);
    if(start == -1) {
        perror("Error seeking in file");
        free(buffer);
        buffer = NULL;
        close(fd_2);
        return 1;
    }
    char * new_string = "100\n";
    ssize_t bytes_written = write(fd_2, new_string, strlen(new_string));
    if(bytes_written == -1) {
        perror("Error writing to file");
        free(buffer);
        buffer = NULL;
        close(fd_2);
        return 1;   
    }
    
    bytes_written = write(fd_2, buffer, remaining);
    if(bytes_written == -1) {
        perror("Error writing to file");
        free(buffer);
        buffer = NULL;
        close(fd_2);
        return 1;
    }

    close(fd_2);
    free(buffer);
    buffer = NULL;

    int final_fd = open(FILENAME, O_RDONLY);
    if(final_fd == -1) {
        perror("Error opening file");
        return 1;  
    }
    char read_char;
    printf("Contents of the file after modification:\n");
    while(1) {
        ssize_t n = read(final_fd, &read_char, 1);
        if(n == -1) {
            perror("Error reading file");
            close(final_fd);
            return 1;
        }
        if(n == 0) {
            break;
        }
        putchar(read_char);
    }
    close(final_fd);

    return 0;
}
