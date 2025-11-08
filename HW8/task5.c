#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "sparse.bin"

int main() {

    int fd = open (FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error opening log file");
        return 1;
    }

    char* start_string = "START";
    size_t string_length = strlen(start_string); 
    ssize_t bytes_written = write(fd, start_string, string_length);
    if(bytes_written == -1) {
        perror("Error writing to file");
        close (fd);
        return 1;
    }

    off_t offset = lseek(fd, 1024 * 1024, SEEK_SET);
    if(offset == -1) {
        perror("Error seeking size");
        close(fd);
        return 1;
    }

    char* end_string = "END";
    size_t end_string_length = strlen(end_string); 
    ssize_t bytes_written_end = write(fd, end_string, end_string_length);
    if(bytes_written_end == -1) {
        perror("Error writing to file");
        close (fd);
        return 1;
    }

    close(fd);

    int fd_2 = open (FILENAME, O_RDONLY, 0644);
    if (fd_2 == -1)
    {
        perror("Error opening log file");
        return 1;
    }
    
    off_t end_pos = lseek(fd_2, 0, SEEK_END);
    if(end_pos == -1) {
        perror("Error seeking size");
        close(fd_2);
        return 1;
    }

    printf("Size of file: %ld\n", end_pos);
    /* The size on disk is smaller because the bytes between "START" and "END" are not actually stored on disk.
     * The gap we created doesn't consume storage. 
     */

    close(fd_2);
    return 0;
    
}
