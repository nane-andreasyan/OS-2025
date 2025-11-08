#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define FILENAME "data.txt"
#define CONTENT "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
int main() {


    int fd = open (FILENAME, O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    ssize_t bytes_written = write (fd, CONTENT, sizeof(CONTENT) - 1);
    if (bytes_written == -1) {
        perror("Error writing to file");
        close (fd);
        return 1;
    }
    close(fd);

    int fd_2 = open (FILENAME, O_RDWR);
    if (fd_2 == -1) {
        perror("Error opening file");
        return 1;
    }

    off_t init_size = lseek(fd_2, 0, SEEK_END);
    if(init_size == -1) {
        perror("Error seeking size");
        close(fd_2);
        return 1;
    }

    printf("Size of file before truncate: %ld\n", init_size);

    if(ftruncate(fd_2, 10) == -1) {
        perror("Error truncating file");
        close(fd_2);
        return 1;
    }

    off_t new_size = lseek(fd_2, 0, SEEK_END);
    if(new_size == -1) {
        perror("Error seeking size");
        close(fd_2);
        return 1;
    }
    printf("Size of file after truncate: %ld\n", new_size);

    off_t pos = lseek(fd_2, 0, SEEK_SET);
    if(pos == -1) {
        perror("Error seeking to beginning");
        close(fd_2);
        return 1;
    }
    char buffer[sizeof(CONTENT)];
    ssize_t bytes_read = read(fd_2, buffer, sizeof(buffer) - 1);

    if (bytes_read == -1) {
        perror("Error reading file");
        close(fd_2);
        return 1;
    }

    buffer[bytes_read] = '\0';
    printf("Bytes read: %zd\n", bytes_read);
    printf("Content of file after truncate: %s\n", buffer);

    close(fd_2);
    return 0;

}
