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
        sleep(5);
        printf("Child process (PID: %d) parent PID: %d\n", getpid(), getppid());
    }
    else {
        printf("Parent process (PID: %d) exiting now\n", getpid());
        exit(0);
    }

    return 0;
}
