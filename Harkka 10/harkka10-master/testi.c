#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[]) {
	int pid = getpid();
	printf("Hey you executed me from another program. Pid is %4d\n", pid);
	int i = 0;
	while (--argc) {
		printf ("Arg %d %s\n", ++i, *++argv);
	}
	return 0;
}
