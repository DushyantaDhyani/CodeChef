#define MOD 1000000007
#include<stdio.h>
long long Power[19];
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
void power(){
	int i=1;
	Power[0]=1;
	while(i<19){
		Power[i]=Power[i-1]*10;
		i++;
	}
}
int main(){
	power();
	int T,N,exp,r,i;
	long long result,tempresult;
	scanf("%d",&T);
	while(T>0){
		scanf("%d",&N);
		result=1;
		exp=0;
		while(N>0){
			r=N%2;
			if(exp<18){
				result=(result*powmod(2,Power[exp]*r,MOD))%MOD;
			}
			else{
				tempresult=powmod(2,Power[18]*r,MOD);
				result=(result*powmod(tempresult,Power[exp-18]*r,MOD))%MOD;
			}
			exp++;
			N=N/2;
		}
		result=powmod(result,2,MOD);
		printf("%lld\n",result);
		T--;
	}
	return 0;
}
