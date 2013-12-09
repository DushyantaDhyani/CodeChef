#define MAX 1000000007
#include<stdio.h>
int getCount(int Num){
	char str[50];
	int ctr=0;
	itoa(Num,str,2);
	int i=0;
	char ch;
	while((ch=str[i])!='\0'){
		if(ch=='1'){
			ctr++;
		}
		i++;
	}
	return ctr;
}
int main(){
	int T;
	int N,G;
	scanf("%d",&T);
	int arr[100000];
	arr[0]=1;
	arr[1]=2;
	int K=2;
	while(T>0){
		scanf("%d %d",&N,&G);
		if(N<=K){
			if(getCount(arr[N-1])==G){
				printf("CORRECT\n");
			}
			else{
				printf("INCORRECT\n");
			}
		}
		else{
			while(K!=N){
				arr[K]=(arr[K-1]+arr[K-2])%MAX;
				K++;
			}
			K--;
			if(getCount(arr[N-1])==G){
				printf("CORRECT\n");
			}
			else{
				printf("INCORRECT\n");
			}
		}
		T--;
	}
	return 0;
}