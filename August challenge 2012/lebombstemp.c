#include<stdio.h>
#include<stdlib.h>
int main(){
	int T;
	scanf("%d",&T);
	int i=1,N,j,ctr;
	char str[1000];
	while(i<=T){
		ctr=0;
		fflush(stdin);
		scanf("%d",&N);
		int arr[N];
		fflush(stdin);
		gets(str);
		j=0;
		while(j<N){
		if(str[j]=='1'){
						if(j==0){
	arr[0]=1;
	arr[1]=1;
	}
	else if(j==(N-1)){
	arr[j]=1;
	arr[j-1]=1;
	}
	else{
	arr[j-1]=1;
	arr[j]=1;
	arr[j+1]=1;
	}
	}
	else{
	if(arr[j]!=1)
	arr[j]=0;
	}
	j++;
	}
	j=0;
	while(j<N){
	if(arr[j]==0)
	ctr++;
	j++;
	}
	printf("%d\n",ctr);
	i++;
	}
	// getch();
	return 0;
	}
