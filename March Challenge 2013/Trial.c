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
	i=0;
	while(i<MAX){
		printf("%d",Arr[i]);
		i++;
	}
	return 0;
}