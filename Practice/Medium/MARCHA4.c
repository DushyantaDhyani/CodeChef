#include<stdio.h>
#include<math.h>
int main(){
	long long int num;
	long num1,num2;
	double temp;
	int k;
	int T;
	int i=1;
	int mod;
	scanf("%d",&T);
	while(T>0){
		scanf("%lld %d",&num,&k);
		temp=num*(double)log10(num);
		num1=floor(pow(10,(temp-floor(temp)))*pow(10,(k-1)));
		printf("%ld ",num1);
		i=2;
		mod=pow(10,k);
		num2=(num%mod);
		while(i<=num){
			num2=(num2%mod*num%mod)%mod;
			i++;
		}
		printf("%ld\n",num2);
		T--;
		
	}
	return 0;
}
