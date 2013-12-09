#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	long T1,T2,T3,T4;
	while(T>0){
		scanf("%ld %ld %ld %ld",&T1,&T2,&T3,&T4);
		printf("%f\n",(T1*1.0/(T1+T2)));
		T--;
	}
	return 0;
}
