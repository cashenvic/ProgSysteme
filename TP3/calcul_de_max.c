#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Personne Personne;
struct Personne {
	char nom[40];
	int age;
};

Personne saisie_personne_suivante() {
	Personne personne;
	printf("Saisir le nom :  ");
	scanf("%s", personne.nom);

	do {
		printf("Saisir son age (entier positif) :  ");
		scanf("%d", &personne.age);
	} while (personne.age < 0);

	return personne;
}

int calcul_max(int nbre_pers, Personne *liste_personnes) {
	int ind_age_max, age_max = 0;

	for (int i = 0; i < nbre_pers; ++i){
		liste_personnes[i] = saisie_personne_suivante();
		if (liste_personnes[i].age > age_max){
			ind_age_max = i;
			age_max = liste_personnes[i].age;
		}
	}

	return ind_age_max;
}

int main(int argc, char const *argv[]){
	Personne *liste_personnes;
	int nbre_pers, ind_age_max;

	if (argc == 2){
		if (!(nbre_pers = atoi(argv[1]))){
			printf("Usage: calcul_max [p]\n\tp: Nombre de personne a saisir\n");
		} else {
			liste_personnes = (Personne*)malloc(sizeof(Personne)*nbre_pers);
			ind_age_max = calcul_max(nbre_pers, liste_personnes);
			printf("La personne la plus agee est: %s\n", liste_personnes[ind_age_max].nom);
		}
	} else {
		printf("Nombre d\'arguments incorrect\n");
		return -1;
	}
	
	return 0;
}