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

	char *mescommande[] = { "who", "cd", "ls", (char *)0 };
	char *paramsWho[] = {"who", (char*)0};
	char *paramsCd[] = {"cd", (char*)0};
	char *paramsLs[] = {"ls", "-l", "/home/cash", (char*)0};

	switch (fork()){
		case -1 :
			fprintf(stderr, "Erreur de fork\n");
			exit(-1);
			break;
		case 0 :// who
			if (execvp(mescommande[0], paramsWho)== -1) {
				perror("execvp");
				exit(-1);
			}
		default : // execution cd
			switch (fork()){
				case -1 :
					fprintf(stderr, "Erreur de fork\n");
					exit(-1);
					break;
				case 0 :
					if (chdir("/home") == -1)
						exit(-1);
					break;
				default : //ls -al
					switch (fork()){
						case -1 :
							fprintf(stderr, "Erreur de fork\n");
							exit(-1);
							break;
						case 0 :
							if (execvp(mescommande[2], paramsLs)== -1) {
								perror("execvp");
								exit(-1);
							}
							break;
						default :
							while (wait(NULL) != -1);
					}
			}
		}
}