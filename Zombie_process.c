#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork Failed\n");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child process (PID: %d) exiting\n", getpid());
        exit(0);
    }
    else {
        printf("Parent process (PID: %d) created child PID: %d\n", getpid(), pid);
        sleep(10);
        printf("Parent exiting\n");
    }

    return 0;
}

