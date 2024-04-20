#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char *argv[])
{
	pid_t pid;
	int id;
	id=fork();
	if(id<0)
	{
		printf("Error in fork");
		exit(0);
	}
	
	else if(id==0)
	{
		if(strcmp(argv[1],"ls")==0)
		{
			execl("/bin/ls","ls",NULL);
		}
		
		else if(strcmp(argv[1],"cp")==0)
		{
			execl("/bin/cp","cp",argv[2],argv[3],NULL);
		}
		
		else if(strcmp(argv[1],"grep")==0)
		{
			execl("/bin/grep","grep",argv[2],argv[3],NULL);
		}
		
		else
		{
			printf("Invalid prompt");
		}
	
	}
	
	else
	{
		int status;
		wait(NULL);
		printf("Child Process executed successfully");
	
	}
	return 0;



}
