#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main()
{
    pid_t pid1, pid2, pid3;
    pid1 = fork();
    if(pid1 == 0){
        char pid1_str[15];
        printf("hello, I am child(pid:%d)\n", getpid());
        snprintf(pid1_str, sizeof(pid1_str), "%d", getpid());
        char *argc[] = {"./cpu", pid1_str, NULL};
        execvp(argc[0], argc);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    pid2 = fork();
    if(pid2 == 0){
        char pid2_str[15];
        printf("hello, I am child(pid:%d)\n", getpid());
        snprintf(pid2_str, sizeof(pid2_str), "%d", getpid());
        char *argc[] = {"./cpu", pid2_str, NULL};
        execvp(argc[0], argc);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    pid3 = fork();
    if(pid3 == 0){
        char pid3_str[15];
        printf("hello, I am child(pid:%d)\n", getpid());
        snprintf(pid3_str, sizeof(pid3_str), "%d", getpid());
        char *argc[] = {"./cpu", pid3_str, NULL};
        execvp(argc[0], argc);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);
    printf("Bye! (from the parent process)\n");
    return 0;
}