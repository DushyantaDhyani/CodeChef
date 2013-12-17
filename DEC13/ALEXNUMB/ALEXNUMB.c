#include<stdio.h>
#include<stdlib.h>
int main(){
	int T;
	int N;
	register int i;
	long long num;
	char name[100];
	scanf("%d",&T);
	while(T>0){
		scanf("%d",&N);
		gets(name);
		num=((long long)N)*(N-1)/2;
		printf("%lld\n",num);
		T--;
	}
	return 0;
}
