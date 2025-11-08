#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 4096


int main() {
    char source_path[256];
    char destination_path[256];

    printf("Please enter the source path\n");
    scanf("%255s", source_path);

    printf("Please enter the destination path\n");
    scanf("%255s", destination_path);

    int fd_source, fd_destination;
    fd_source = open (source_path, O_RDONLY);

    if (fd_source == -1) {
        printf("Error opening source file\n");
        return 1;
    }

    fd_destination = open (destination_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);


    if (fd_destination == -1) {
        printf("Error opening destination file\n");
        return 1;
    }

    char buf[BUF_SIZE];
    ssize_t bytes_read, bytes_written;
    ssize_t total_bytes_written = 0;

    while ( (bytes_read = read (fd_source, buf, BUF_SIZE)) != 0) {
         if (bytes_read == -1) {
            if (errno == EINTR)
                continue;
             perror("Error reading source file");
                return 1;
        }
        ssize_t index = 0;
        while (index < bytes_read) {
            bytes_written = write(fd_destination, buf + index, bytes_read - index);
            if (bytes_written == -1) {
                perror("write");
                close(fd_source);
                close(fd_destination);
                return 1;
            }
            index += bytes_written;
        }
         total_bytes_written += index;
    }

    printf("Copied %zd bytes successfully.\n", total_bytes_written);

    close(fd_source);
    close(fd_destination);
    return 0;

}
