#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int main(){
	pthread_t tid;

	void *thread_function(void * parm){
		printf("[thread]:My pid is %d .\n",getpid());
	}
	printf("[Main]: My pid is : %d .\n",getpid());

	pthread_create(&tid,NULL,&thread_function,NULL);//after the call the origin thread created by the processus continue execution the next instruction ,
	//pthread_create :  create a thread
	sleep(1);
	return 0;
}
