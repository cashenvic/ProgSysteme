#include <stdio.h>
#include <stdlib.h>
#include "exo2_fcts.h"

int main(void) {
  float *tab, min;
  int indicemin, nb;

  printf("Combien d'elements voulez-mettre dans le tableau? ");
  scanf("%d", &nb);

  tab = (float*)malloc(nb*sizeof(float));

  remplir(tab, nb);

  min = calcul_min(tab, nb, &indicemin);
  printf("Plus petit element = %f, a l'indice %d\n", min, indicemin);

  return 0;
 }