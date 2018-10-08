#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define ECRITURE 1
#define LECTURE 0

void initPipe(int p[2], int valChanged) {

	close(valChanged);
	dup(p[valChanged]);
	close(p[valChanged]);
	close(p[!valChanged]);
}
int main(int argc, char const *argv[]) {

	int p1[2], p2[2];

	pipe(p1);
	pipe(p2);


	switch(fork()){
		case -1: 
		 	perror("fork"); 
			exit(1);
		case 0:	

			initPipe(p1, ECRITURE);
 			execlp("ps","ps","ax",(char *)0);	
		default: 
			switch(fork()){
				case -1: 
				 	perror("fork"); 
					exit(1);
				case 0:	

					initPipe(p1, LECTURE);
					initPipe(p2, ECRITURE);	
					execlp("grep", "grep", "bash", (char *)0);	
 				default:
 					close(p1[0]);
 					close(p1[1]);
 					switch(fork()) {
 						case -1: 
	 						perror("fork");
	 						exit(1);
 						case 0:
 							initPipe(p2, LECTURE);
 							execlp("wc", "wc", "-l", (char *)0);
 						default:
 							close(p2[0]);
 							close(p2[1]);
 							while(wait(NULL) != -1);
 					}
	return 0;
}