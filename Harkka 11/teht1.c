#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define FILENAME "test.txt"
void close123() {
    unlink(FILENAME);
    printf("Normal exit\n");

}
int main() {
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