#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
//the end goal is to crate a programme that allow to processus ,father and son to communicate with each other . to do so we need to pipe
int main(){
	int  pid;
	int fatherToson[2],sonTofather[2];
	int nbR,nbW;
	char messageFather[]=" Message from father = (Hello son i am your father !)";
	char messageSon[]=" Message from son = (Hello father .)";

	char *buffRead=(char *)malloc(sizeof(strlen(messageSon)));
	char *buffWrite=(char *)malloc(sizeof(strlen(messageFather)));
	pipe(fatherToson),pipe(sonTofather);//create a pipe with two edges 1 and 0 ; 1 for read and 0 to write
	pid=fork();//fork create processus ; return 0 if the chiled processus is created ,else -1
	if(pid	==	0){ 	//means the son is created ,
		close(fatherToson[1]),close(sonTofather[0]);// son read from the pipe comming from the father 
		// and he will write in the other pipe (son->father)
		// F write  p1----p0 read S//S write s1----s0 read F.
		nbR=read(fatherToson[0],buffRead,strlen(messageFather));
		printf("[son]: reading %d of data \n",nbR);
		printf("[son]: the message is (%s)\n",buffRead);
		write(sonTofather[1],messageSon,strlen(messageSon));
		printf("[son]:response is sent. \n");
		close(fatherToson[0]),close(sonTofather[1]);
	}
	else{
		close(fatherToson[0]),close(sonTofather[1]);
		printf("[father]:sending message .\n");
		write(fatherToson[1],messageFather,strlen(messageFather));	
		nbW=read(sonTofather[0],buffWrite,strlen(messageSon));
		printf("[father]:recived  message (%s) of length %d  .\n",buffWrite,nbW);
		
	wait(NULL);
		close(fatherToson[1]),close(sonTofather[0]);	
		
	}
	return 0;
}

