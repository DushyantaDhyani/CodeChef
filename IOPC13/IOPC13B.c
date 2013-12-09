#include<stdio.h>
int main(){
	int T;
	long N,M;
	long sum;
	scanf("%d",&T);
	while(T>0){
		scanf("%ld %ld",&M,&N);
		sum=(M*(M-1))/2;
		sum=sum%M;
		sum=(sum*(N%M))%M;
		sum*=2;
		printf("%ld\n",sum);
		T--;
	}
	return 0;
}