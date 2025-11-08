#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {

    char source_path[256];
    printf("Please enter the source path\n");

    scanf("%255s", source_path);
    int fd = open (source_path, O_RDONLY);

    if(fd == -1) {
        perror("Error opening source file");
        return 1;
    }

    off_t file_size = lseek(fd, 0, SEEK_END);
    if (file_size == -1) {
        perror("Error seeking to end of file");
        close(fd);
        return 1;
    }

    if(file_size > 0){
        while(file_size>0) {
            char ch;
            off_t pos = lseek (fd, file_size - 1, SEEK_SET);
            if (pos == -1) {
                perror("Error seeking in file");
                close(fd);
                return 1;
            }
            ssize_t bytes_read = read (fd, &ch, 1);
            if (bytes_read == -1) {
                perror("Error reading file");
                close(fd);
                return 1;
            }
            printf("%c", ch);
            file_size--;

        }
    }

    printf("\n");

    close(fd);
    return 0;

}


