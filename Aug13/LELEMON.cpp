#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int T;
	int N,M;
	int i,j;
	int C;
	long Total;
	scanf("%d",&T);
	while(T>0){
		Total=0;
		scanf("%d %d",&N,&M);
		vector<int> Path(M);
		vector< vector<int> > Data(N);
		i=0;
		while(i<M){
			scanf("%d",&Path[i]);
			i++;
		}
		i=0;
		while(i<N){
			scanf("%d",&C);
			Data[i].resize(C);
			j=0;
			while(j<C){
				scanf("%d",&Data[i][j]);
				j++;
			}
			sort(Data[i].begin(),Data[i].end());
			i++;
		}
		i=0;
		while(i<M){
			if(Data[Path[i]].size()!=0){
				Total+=Data[Path[i]].back();
				Data[Path[i]].pop_back();
			}
			i++;
		}
		printf("%ld\n",Total);
		T--;
	}
	return 0;
}
