#include <stdio.h>
#include <stdlib.h>

void remplir(float *tab, int nb) {
  for (int i=0; i<nb; i++) {
    printf("Saisir tab[%d] : ", i+1);
    scanf("%f", &tab[i]);
  }
}

float calcul_min(float *tab, int nb, int *p) {
  float min = tab[0];
  for(int i=0; i<nb; i++){
    if (tab[i]<min) {
       min = tab[i];
       *p = i;
    }
  }
  return min;
}