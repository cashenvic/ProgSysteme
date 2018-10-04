#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char const *argv[]) {
	/*	
		( who ; cd ; ls -l ) liste de façon detaillé le contenu du repertoire courant 
		sans se deplacer dans le dossier cible
	
		who ; cd ; ls -l liste de façon detaillé le contenu du dossier courant 
		en se deplaçant cette fois dans le repertoire de login du user 
	*/

	char *macommande[3] = { "(who; cd; ls; -al)", "../", (char *)0 };

	switch (fork()){
		case -1 :
			fprintf(stderr, "Erreur de fork\n");
			exit(-1);
			break;
		case 0 :
			if (execvp("ls", macommande)== -1) {
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