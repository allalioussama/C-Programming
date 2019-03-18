#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc ,char *argv[]){
		int pid[3];
		int max=0,min=0,sum=0,i;

		pid[0]=fork();
		if(pid[0]==0){
				printf("I am the son %d , me father is %d\n",getpid(),getppid());
				for( i=0;i<argc;i++)
						sum+=atoi(argv[i]);

				printf("the sum of the inputs is :%d\n",sum);
		}else{
				printf("%d\n",getpid());
				printf("%d\n",pid[0]);
		}

		pid[1]=fork();
		if(pid[1]==0){
				printf("I am the son %d , me father is %d\n",getpid(),getppid());
				max=atoi(argv[0]);
				for(i=1;i<argc;i++){
						if(atoi(argv[i])>max)
							max=atoi(argv[i]);
				}
				printf("the max of the inputs is :%d\n",max);

		}else{
				printf("%d\n",getpid());
				printf("%d\n",pid[1]);
		}

		pid[2]=fork();
		if(pid[2]==0){
				printf("I am the son %d , me father is %d\n",getpid(),getppid());
				min=atoi(argv[0]);
				for(i=1;i<argc;i++){
						if(atoi(argv[i])<min)
							min=atoi(argv[i]);
				}
				printf("the min of the inputs is :%d\n",min);

		}else{
				printf("%d\n",getpid());
				printf("%d\n",pid[2]);
		}
		return EXIT_SUCCESS;
		}
