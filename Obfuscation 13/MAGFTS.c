#define MAX 1000000
#include<stdio.h>
#include<math.h>
int flag[MAX+1];
int FLAG[100000];
int K;
void setPrimeFlags(){
        	int i,j;
			 i=0;
			 while(i<=MAX){
			 	flag[i]=1;
			 	i++;
			 }
			 int limit=sqrt(MAX);
			 i=2;
			 while(i<=limit){
			 	if(flag[i-1]){
			 	    FLAG[K++]=i;
			 		j=i;
			 		while(j*i<MAX){
			 			flag[j*i-1]=0;
			 			j++;
			 		}
			 	}
			 	i++;
			 }
			 while(i<(MAX)){
                if(flag[i-1]){
                    FLAG[K++]=i;
                }
                i++;
             }
}
int checkPrime(long long num){
	int i=0;
	while(i<K){
		if(num%(long long)FLAG[i]==0){
			if(num==FLAG[i]){
				return 1;
			}
			else{
				return 0;
			}
		}
		i++;
	}
	return 1;
}
int main(){
	int T;
	long long N;
	scanf("%d",&T);
	setPrimeFlags();
	while(T>0){
		scanf("%lld",&N);
		if(N%(long long)2==0){
			printf("1\n");
		}
		else{
			if(checkPrime(N)){
				printf("2\n");
			}
			else{
				printf("1\n");
			}
		}
		T--;
	}
	return 0;
}