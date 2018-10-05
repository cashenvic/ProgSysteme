#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char const *argv[]) {
	/*	
		ps ax | grep bash
	
		ps ax | grep bash | wc -l
	*/

	//char *macommande[3] = { "ps", "ax", " | grep bash | wc -l", (char *)0 };
	char *macommande[2] = { "ax", (char *)0 };

	switch (fork()){
		case -1 :
			fprintf(stderr, "Erreur de fork\n");
			exit(-1);
			break;
		case 0 :
			if (execvp("ps", macommande)== -1) {
				perror("execvp");
				exit(-1);
			}
			break;
		default :
			printf("Le fils %d est mort\n", wait(NULL));
			return 0;
	}

	return 0;
}