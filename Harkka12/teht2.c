#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>

static void IntHandler(int sig) {
    pid_t prosessiID = fork();
    if (prosessiID == 0) {
    //write(STDERR_FILENO, "Switched to child\n", 20);
    }
    else {
        int parent = getppid();
        kill(parent,SIGTERM);
        _exit(1);
    }
}
int main(int argc, char *argv[]) {
    if (signal(SIGINT, IntHandler) == SIG_ERR) {
        perror("signal SIGINT");
    }
    int nro = atoi(argv[1]);
    printf("Lasketaan alaspäin %d sekunnista\n",nro);
    while(nro>=0) {
        printf("%d\n",nro);
        nro = nro-1;
        sleep(1);
    }
    exit(1);
}