#include <stdio.h>

int main(int argc, char const *argv[])
{
	int nb1 = 0, nb2 = 0;
	printf("Saisissez 2 valeurs\n");
	scanf("%d", &nb1);
	scanf("%d", &nb2);
	printf("Le nombre 1 vaut: %d et le nombre 2 vaut %d\n", nb1, nb2);
	scanf("%d", &nb2);
	return 0;
}