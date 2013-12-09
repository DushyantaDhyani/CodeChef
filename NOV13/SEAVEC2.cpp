#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int T,N,M;
	int i,j;
	scanf("%d",&T);
	while(T>0){
		scanf("%d %d",&N,&M);
		vector< vector<long> > Data(N,vector<long>(M+1));
		vector< vector<long> >::iterator it;
		vector<long>::iterator itr;
		vector<long> A1(M),A2(M);
		vector<int> Result1,Result2;
		long long TotalSum1,TotalSum2;
		TotalSum1=TotalSum2=0;
		i=0;
		while(i<N){
			j=1;
			Data[i][0]=i+1;
			while(j<=M){
				scanf("%ld",&Data[i][j]);
				j++;
			}
			i++;
		}
		i=0;
		while(i<M){
			scanf("%ld",&A1[i]);
			A2[i]=A1[i];
			TotalSum1+=A1[i];
			i++;
		}
		TotalSum2=TotalSum1;
		it=Data.begin();
		while(it!=Data.end()){
			i=0;
			while(i<M){
				if((*it)[i+1]>A1[i]){
					break;
				}
				i++;
			}
			if(i<M){
				Data.erase(it);
			}
			else{
				it++;
			}
		}
		N=Data.size();
		i=N-1;
		while(i>=0){
			j=0;
			while(j<M){
				if(!(Data[i][j+1]<=A1[j])){
					break;
				}
				j++;
			}
			if(j>=M){
				//flag++;
				Result1.push_back(Data[i][0]);
				j=0;
				while(j<M){
					A1[j]=A1[j]-Data[i][j+1];
					TotalSum1-=Data[i][j+1];
					j++;
				}
			}
			i--;
		}
		i=0;
		//int flag=0;
		while(i<N){
			j=0;
			while(j<M){
				if(!(Data[i][j+1]<=A2[j])){
					break;
				}
				j++;
			}
			if(j>=M){
				//flag++;
				Result2.push_back(Data[i][0]);
				j=0;
				while(j<M){
					A2[j]=A2[j]-Data[i][j+1];
					TotalSum2-=Data[i][j+1];
					j++;
				}
			}
			i++;
		}
		/*i=0;
		while(i<N){
			j=1;
			while(j<=M){
				printf("%ld ",Data[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}*/
		sort(Result1.begin(),Result1.end());
		sort(Result2.begin(),Result2.end());
		if(Result1.size()!=0){
			if(Result2.size()!=0 && (Result2.size()*1.0/(TotalSum2+1))> (Result1.size()*1.0/(TotalSum1+1))){
				printf("%d\n",Result2.size());
				i=0;
				while(i<Result2.size()){
					printf("%d ",Result2[i]);
					i++;
				}
				printf("\n");
			}
			else{
				printf("%d\n",Result1.size());
				i=0;
				while(i<Result1.size()){
					printf("%d ",Result1[i]);
					i++;
				}
				printf("\n");
			}
		}
		else{
			printf("0\n");
		}
		T--;
	}
	return 0;
}
