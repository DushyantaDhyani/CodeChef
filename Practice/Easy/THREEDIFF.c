#define MOD 1000000007
#include<stdio.h>
int main(){
	int T;
	long long num1,num2,num3;
	long long min1,min2,min3;
	long long result;
	scanf("%d",&T);
	while(T>0){
		scanf("%lld %lld %lld",&num1,&num2,&num3);
		if(num1<num2){
			if(num1<num3){
				min1=num1;
				if(num2<num3){
					min2=num2;
					min3=num3;
				}
				else{
					min2=num3;
					min3=num2;
				}
			}
			else{
				min1=num3;
				min2=num1;
				min3=num2;	
			}
		}
		else{
			if(num2<num3){
				min1=num2;
				if(num1<num3){
					min2=num1;
					min3=num3;
				}
				else{
					min2=num3;
					min3=num1;
				}
			}
			else{
				min1=num3;
				min2=num2;
				min3=num1;
			}
		}
		result=1;
		result=(result*(min1)%MOD)%MOD;
		result=(result*((min2-1)%MOD))%MOD;
		result=(result*((min3-2)%MOD))%MOD;
		printf("%lld\n",result);
		T--;
	}
	return 0;
}
