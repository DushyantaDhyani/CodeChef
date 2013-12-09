#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int T;
	int N;
	long K;
	int j,i,k;
	int flag;
	scanf("%d",&T);
	while(T>0){
		scanf("%d %ld",&N,&K);
		vector<long> Arr1(N+2);
		vector<long> Arr2(N+2);
		i=1;
		while(i<=N){
			cin>>Arr1[i];
			i++;
		}
		Arr1[0]=Arr1[N];
		Arr1[N+1]=Arr1[1];
		flag=1;
		j=1;
		if(K%3==0){
			K=3;
		}
		else if(K%3==2){
			 K=2;
		}
		else{
			K=1;
		}
		while(j<=K){
			if(flag){
				k=1;
				while(k<=N){
					Arr2[k]=Arr1[k-1]^Arr1[k]^Arr1[k+1];
					k++;
				}
				Arr2[0]=Arr2[N];
				Arr2[N+1]=Arr2[1];
				flag=0;
			}
			else{
				k=1;
				while(k<=N){
					Arr1[k]=Arr2[k-1]^Arr2[k]^Arr2[k+1];
					k++;
				}
				Arr1[0]=Arr1[N];
				Arr1[N+1]=Arr1[1];
				flag=1;
			}
			j++;
		}
		if(K%2!=0){
			i=1;
			while(i<=N){
				cout<<Arr2[i]<<" ";
				i++;
			}
			printf("\n");
		}
		else{
			i=1;
			while(i<=N){
				cout<<Arr1[i]<<" ";
				i++;
			}
			printf("\n");
		}
		T--;
	}
	return 0;
}