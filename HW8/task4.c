#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>


#define FILENAME "log.txt"

int main() {

    int fd = open (FILENAME, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1)
    {
        perror("Error opening log file");
        return 1;
    }

    pid_t pid = getpid();
    char pid_str[128];
    int len = snprintf(pid_str, sizeof(pid_str), "PID=%d: ", pid);
    if (len < 0) {
        perror("Error formatting PID string");
        close(fd);
        return 1;
    }

    size_t log_size = 256;
    char *log_entry = malloc(log_size);

    if (!log_entry) {
        perror("Error allocating memory");
        return 1;
    }

    char c;
    size_t bytes_read = 0;


    while(1) {
        ssize_t n = read(0, &c, 1); 
        if(n == -1) {
            perror("Error reading from stdin");
            close(fd);
            return 1;
        }

        if(n == 0) {
            break; 
        }

        if(bytes_read>=log_size - 1) {
            log_size *= 2;
            char *new_log_entry = realloc(log_entry, log_size);
            if(new_log_entry == NULL) {
                perror("Error reallocating memory");
                free(log_entry);
                close(fd);
                return 1;
            }
            log_entry = new_log_entry;
        }

        log_entry[bytes_read++] = c;

        if (c == '\n') {
            break;
        }
    }


    if (bytes_read == 0 || log_entry[bytes_read - 1] != '\n') {
        log_entry[bytes_read++] = '\n';
    }

    log_entry[bytes_read] = '\0';


    ssize_t bytes_written  = write(fd, pid_str, len);
    if(bytes_written == -1) {
        perror("Error writing to file");
        close (fd);
        return 1;
    }

    ssize_t bytes_written_2  =write(fd, log_entry, strlen(log_entry));
    if(bytes_written_2 == -1) {
        perror("Error writing to file");
        close (fd);
        return 1;
    }

    off_t pos = lseek(fd, 0, SEEK_CUR);
    if (pos == -1) {
        perror("Error seeking");
        close(fd);
        return 1;
    }

    /*The offset keep growing because in append mode the cursor 
     *always goes ot the EOF which grows after each write.
     */

    printf("Current file offset: %ld\n", pos);

    free(log_entry);
    log_entry = NULL;
    close(fd);
    return 0;

}
