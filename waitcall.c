#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t p = fork();

    if (p < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (p == 0) {
        printf("Child process is created\n");
    }
    else {
        wait(NULL);
        printf("I am parent process\n");
    }

    return 0;
}
