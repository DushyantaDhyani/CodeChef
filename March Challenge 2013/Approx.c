#define MAX 1000000
#include<stdio.h>
#include<string.h>
int main(){
	short Arr[MAX];
	int num=4687;
	int div=33102;
	int i=0;
	int T,K;
	while(i<MAX){
		num=num*10;
		while(num<div && i<MAX){
			Arr[i++]=0;
			num*=10;
		}
		if(i<MAX){
			Arr[i++]=num/div;
			num=num%div;
		}
	}
	scanf("%d",&T);
	while(T>0){
		scanf("%d",&K);
		if(K==0){
			printf("3\n");
		}
		else{
			printf("3.");
			i=0;
			while(i<K){
				printf("%d",Arr[i]);
				i++;
			}
			printf("\n");
		}
		T--;
	}
	return 0;
}