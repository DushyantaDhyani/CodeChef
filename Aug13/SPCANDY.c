#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	unsigned long long N,K;
	while(T>0){
		scanf("%lld %lld",&N,&K);
		if(N==0){
			printf("0 0\n");
		}
		else if(K==0){
			printf("0 %lld\n",N);	
		}
		else{
			printf("%lld %lld\n",(N/K),(N%K));
		}
		T--;
	}
	return 0;
}
