#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
int main(){
    pid_t p=fork();
    if(p==0){
        printf("Child process is sleeped\n");
    }
    else if(p>1){
        wait(NULL);
        printf("Parent process is here");
        sleep(10);
        printf("Parent after sleeping");
        wait(NULL);
    }
    return 0;
}