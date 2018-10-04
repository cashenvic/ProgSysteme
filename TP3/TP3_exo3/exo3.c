#include <stdio.h>
#include <stdlib.h>

char *convert_vers_bin(int x, int n) {
	char *bin = (char*)malloc(sizeof(char)*n);

	for (int i=0; i < n; i++) {
		bin[i] = x%2;
		x /= 2;
	}

	return bin;
}

/*char *convert_vers_dec(int v[], int n) {
	char *conv;

	for (int i = 0; i < strlen(v); ++i){
		conv += V[i]-'0' ;
	}
}*/

void affichage_bin(char *bin, int n) {
	for (int i = n; i >= 0; --i)
	{
		printf("%d ", bin[i]);
	}
}

int main(int argc, char const *argv[]) {
	int dec, n;
	char *bin;

	printf("Saisir l'entier a convertir: ");
	scanf("%d", &dec);
	printf("Sur combien de bits convertir cet entier? \n");
	scanf("%d", &n);


	bin = convert_vers_bin(dec, n);
	affichage_bin(bin, n);
	
	return 0;
}