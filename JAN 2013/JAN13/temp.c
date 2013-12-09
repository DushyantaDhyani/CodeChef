#include<stdio.h>
#include<malloc.h>
int main() {
int a = 10;
int *b = malloc(10 * sizeof(int));
b[-1]++;
printf("%d\n",b[-1]);
printf("%d\n", a);
}
