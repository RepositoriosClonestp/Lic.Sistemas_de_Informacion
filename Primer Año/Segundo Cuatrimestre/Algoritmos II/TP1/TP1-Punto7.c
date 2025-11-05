#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
  typedef int * tpEntero;
  typedef char * tpCaracter;

  tpEntero p1, p2;
  tpCaracter q1, q2, q3;

  p1 = malloc(sizeof(int));
  p2 = malloc(sizeof(int));
  *p1 = 5;
  *p2 = *p1 + 20;
  printf("*p1 igual a %d, *p2 igual a %d\n", *p1, *p2);

  p2 = malloc(sizeof(int));
  *p2 = 2;
  *p2 = pow(*p2, 2);
  p1 = malloc(sizeof(int));
  *p1 = fmod(*p2, 3);
  printf("*p1 igual a %d, *p2 igual a %d\n", *p1, *p2);

  q1 = malloc(sizeof(char));
  q2 = malloc(sizeof(char));
  q3 = malloc(sizeof(char));
  *q1 = 'Y';
  *q2 = (*q1) - 1;
  *q3 = (*q1) + 1;
  printf("*q1 igual a %c, *q2 igual a %c, q3 igual a %c\n", *q1, *q2, *q3);

  return 0;
}
