#include<stdio.h>
#include<stdlib.h>
int main(){
	long arr[100][1000];
	int i,j;
	i=0;
	printf("%d\n",1);
	printf("%d %d\n",100,1000);
	while(i<100){
		j=0;
		while(j<1000){
			arr[i][j]=rand()%1000;
			printf("%ld ",arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	j=0;
	while(j<1000){
		printf("%ld ",(long)(rand()%1000000));
		j++;
	}
	printf("\n");
	return 0;
}
