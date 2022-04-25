#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>


int main(int argc, char *argv[]) {
	struct flock f1;
	time_t t;
	char* file = argv[1];
	pid_t pid;	
	
	int fd = open(argv[1], O_RDWR);
        if(fd == -1) {
                printf("Unable to open the file\n");
                exit(1);
        }
        
        pid = getpid();
        
        time(&t);
        printf("pid: %3d, getting exclusive lock at %s\n", pid, ctime(&t));
        flock(fd, LOCK_EX);
        time(&t);
        printf("pid: %4d, exclusive locked at %s\n", pid, ctime(&t));
        sleep(20);
        
        flock(fd, LOCK_UN);
        time(&t);
        printf("pid: %4d, unlocked at %s\n", pid, ctime(&t));
        
        flock(fd, LOCK_SH);
        time(&t);
        printf("pid: %3d, getting shared lock at %s\n", pid, ctime(&t));
        time(&t);
        printf("pid: %4d, share locked at %s\n", pid, ctime(&t));
        sleep(20);
        time(&t);
        flock(fd, LOCK_UN);
        printf("pid: %4d, unlocked at %s\n", pid, ctime(&t));
           

}
