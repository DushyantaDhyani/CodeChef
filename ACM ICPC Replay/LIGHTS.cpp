#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	int T;
	int N,M,K;
	int i,j,k;
	char ch;
	int FinalVal;
	int count;
	scanf("%d",&T);
	string str;
	while(T>0){
		FinalVal=0;
		int arr[M];
		scanf("%d %d %d",&N,&M,&K);
		i=0;
		while(i<N){
			count=0;
			cin>>str;
			j=0;
			while(j<M){
				if(str[j]=='.'){
					count++;
				}
				j++;
			}
			arr[count-1]++;
			i++;
		}
		j=M-1;
		while(K>=0){
			if(arr[j]==0){
				j--;
			}
			else{
				arr[M-j]++;
				arr[j]--;
			}
		}
		i=0;
		while(i<M){
			FinalVal+=
		}
		T--;
	}
	return 0;
}