#include<stdio.h>
int main(){
	int N=100000;
	printf("%d\n",N);
	int i=1;
	long num;
	while(i<=N){
		num=rand()%100000;
		printf("%ld ",num);
		i++;
	}
	printf("\n");
	return 0;
}
