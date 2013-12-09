#define MAX 100000
#include<stdio.h>
#define s(T) scanf("%d", &T)
#define sn(N) scanf("%d", &N)
void swap(int *num1,int *num2){
	int temp=*num1;
	*num1=*num2;
	*num2=temp;
}
int arr[MAX];
int getGCF(int num1,int num2){
	int temp;
	while(num2){
		temp=num1;
		num1=num2;
		num2=temp%num2;
	}
	return num1;
}
int main(){
	int T;
	int N;
	register int i;
	int val=-1;
	s(T);
	while(T>0){
		sn(N);
		i=0;
		while(i<N){
			scanf("%d",&arr[i]);
			i++;
		}
		i=1;
		val=getGCF(arr[i-1],arr[i]);
		i=2;
		while(i<N){
			val=getGCF(val,arr[i]);
			if(val<=1){
				val=-1;
				break;
			}
			i++;
		}
		printf("%d\n",val);
		T--;
	}
	return 0;
}
