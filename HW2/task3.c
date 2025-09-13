#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>

int main() 
{ 
        int pid_1 = fork();
        if (pid_1 < 0) {
            perror("fork1");
        }

        if(pid_1 == 0) {
            execl("/bin/ls", "ls", NULL);
            perror("exec1");
        }

        int pid_2 = fork();
        if (pid_2 < 0) {
            perror("fork2");
        }

        if(pid_2 == 0) {
            execl("/bin/date", "date", NULL);
            perror("exec2");
        }

        while (wait(NULL) > 0) {}
        //with waitpid
        //waitpid(pid_1, NULL, 0);
        //waitpid(pid_2, NULL, 0);
        //with regular wait()
        //wait()
        //wait()

        printf("Parent process done\n");

} 