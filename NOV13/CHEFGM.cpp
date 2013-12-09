#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int T;
	int K,N;
	int i,j;
	scanf("%d",&T);
	while(T>0){
		scanf("%d",&K);
		vector< vector<long> > Data(K);
		i=0;
		while(i<K){
			scanf("%d",&N);
			Data[i].resize(N);
			j=0;
			while(j<N){
				scanf("%ld",&Data[i][j]);
				j++;
			}
			sort(Data[i].begin(),Data[i].end());
			i++;
		}
		int evencount=0,oddcount=0;
		i=0;
		while(i<K){
			j=0;
			while(j<N){
				if(j>=1 && Data[i][j]!=Data[i][j-1] && (Data[i][j]%2)==0){
					evencount++;
				}
				else if((Data[i][j]%2)==0){
					evencount++;
				}
				else{
					break;
				}
				j++;
			}
			i++;
		}
		i=0;
		while(i<K){
			j=0;
			while(j<N){
				if(j>=1 && Data[i][j]!=Data[i][j-1] && (Data[i][j]%2)!=0){
					oddcount++;
				}
				else if((Data[i][j]%2)!=0){
					oddcount++;
				}
				else{
					break;
				}
				j++;
			}
			i++;
		}
		if(oddcount==evencount){
			printf("DON'T PLAY\n");
		}
		else if(oddcount<evencount){
			printf("EVEN\n");
		}
		else{
			printf("ODD\n");
		}
		T--;
	}
	return 0;
}
