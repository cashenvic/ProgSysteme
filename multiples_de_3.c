#include <stdio.h>

int main(int argc, char const *argv[])
{
	int borneInf, borneSup;
	printf("Saisissez la borne inferieure\n");
	scanf("%d", &borneInf);
	printf("Saisissez la borne superieure\n");
	scanf("%d", &borneSup);

	if ((borneInf % 3) != 0) {
		borneInf -= (borneInf % 3);
	}

	for (int i = borneInf+3; i < borneSup; i += 3) {
		printf("%d,  ", i);
	}
	//KPzgHqujY3QY

	return 0;
} 