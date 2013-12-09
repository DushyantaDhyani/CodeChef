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
	long long N,M,Q,K;
	long long result,d;
	scanf("%d",&T);
	while(T>0){
		scanf("%lld %lld %lld %lld",&N,&M,&Q,&K);
		if((M-Q)>0){
			d=powmod(Q+1,N,MOD)-(2*powmod(Q,N,MOD))%MOD+powmod(Q-1,N,MOD);
			if(d<0){
				d=((d%MOD)+MOD)%MOD;	
			}
			result=(((M-Q)%MOD)*(d%MOD))%MOD;			
			printf("%lld\n",result);
		}
		else{
			printf("0\n");
		}
		T--;
	}
	return 0;
}
