#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t pid;
    for(int i = 0; i < 1000; i++){
        pid = fork();
        if(pid == 0) exit(EXIT_SUCCESS);
        else if(pid < 0){
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }
    while(1){
        sleep(1);
    }
    return 0;
}