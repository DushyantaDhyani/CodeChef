#include<stdio.h>
int main(){
	long N,M;
	scanf("%ld %ld",&N,&M);
	long i,j;
	short flag=1;
	short num1,num2,num3;
	num1=num2=num3=10;
	i=0;
	while(i<N){
		scanf("%d",&num2);
		if(num1==num2){
			printf("NO Broke Because of same rows \n");
			flag=0;
			break;
		}
		j=1;
		while(j<M){
			scanf("%d",&num3);
			if(num3!=num2){
				flag=0;
				printf("NO\n");
				break;
			}
			j++;
		}
		if(!flag){
			break;
		}
		num1=num2;
		i++;
	}
	if(flag){
		printf("YES\n");
	}
	return 0;
}