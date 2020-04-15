#include <stdio.h>

typedef struct ej{
    int a;
    char b;
    int* c;
}__attribute__((packed)) ej_t;

int main()
{
    printf("El tamaño de a, b y c, es, respectivamente, %lu, %lu y %lu\n", sizeof(int), sizeof(char),sizeof(int*));
    printf("El tamaño del struct {a,b,c} es %lu\n", sizeof(ej_t));
    return 0;
}