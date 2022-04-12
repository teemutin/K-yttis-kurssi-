#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#define FILENAME "test.txt"
void close123() {
    unlink(FILENAME);
    printf("Normal exit\n");

}
static void IntHandler(int sig) {
    unlink(FILENAME);
    write(STDERR_FILENO, "Process interrupted\n", 20);
    exit(1);
}
int main(int argc, char *argv[]) {
    if (signal(SIGINT, IntHandler) == SIG_ERR) {
        perror("signal SIGINT");
    }
    int i = 0;
    FILE* temp = tmpfile();
    temp = fopen("test.txt","w");
    if (temp == NULL)
    {
        puts("Unable to create temp file");
        return 0;
    }
    puts("Temporary file is created\n");
    while (i<5)
    {
        fputc(i, temp);
        i++;
        printf("Writing %d\n", i);
        sleep(1);
        
    }
    fclose(temp);
    atexit(close123);
}