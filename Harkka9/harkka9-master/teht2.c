#include <stdio.h>

int main(int argc, char *argv[], char * envp[]) {
    int y;
    int i;
    for (i = 0; envp[i] != NULL; i++) {
        printf("%s\n", envp[i]);
    }
    for (y=1; y<argc; y++) {
        printf("%s\n", argv[y]);
    }
}