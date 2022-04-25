#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 

int main(int argc, char *argv[]) {
	//Lähde https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1044654269&id=1043284392
	int status;
	char testi[BUFSIZ];
	strcpy (testi, "./test");
	strcat (testi, " -arg1 -arg2");

	//System
	char* file = argv[1];
	//char tdst[] = "./test";
	
	//printf("Executing test program1\n");
	//system("./test");
	printf("Current Pid%d \n",getpid());
	printf("Executing test program with system\n");
	system(testi);
	printf("Current Pid%d \n",getpid());
	//printf("ls\n");
	//system("ls");
	//printf("ls -l\n");
	//system("ls -l \*.c");
	//system(tdst);
	
	//Exec
	pid_t pid;
	//printf("pida: %4d\n", pid);
	char *args[5];
	args[0] = "test";
	args[1] = "arg1";
	args[2] = "arg2";
	args[3] = NULL;
	//char * const args[]={"/bin/sh","-c","ls","-l",NULL};
	//char * const args[]={"/bin/ls","-l","*.c",NULL};
	/*args[0] = "/bin/ls";
	args[1] = "-l";
	args[2] = " *.C";
	args[3] = NULL;*/
	printf("Executing test program with exec\n");
	switch((pid = fork())) 
	{
		case -1:
			perror ("fork");
			break;
		case 0:
			printf("Child Pid %d, parent Pid%d \n",getpid(),getppid());
			execv("test", args);
			//execv(args[0], args);
			
			break;
		default:
			printf("Status %d\n",status);
			//printf("Neljäs\n");
			wait (&status);
			printf("Status %d\n",status);
			break;
	} 
	//printf("Viides\n");
	//printf("pid: %4d\n", pid);
	
	
	return 0;
	
	
}
