#define MOD 1000000007
#include<stdio.h>
long long powmod(long long base,long long power,long long mod){
	long long result=1;
	base%=mod;
	while(power>0){
		if(power & 1){
			result=(result*base)%mod;
		}
		base=(base*base)%mod;
		power>>=1;
	}
	return result;
}
int main(){
	int T;
	long long N;
	scanf("%d",&T);
	while(T>0){
		scanf("%lld",&N);
		printf("%lld\n",((powmod(2,N,MOD)-1)%MOD));
		T--;
	}
	return 0;
}
