#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct node{
	int C;
	int U,D,L,R;
};
int main(){
	int N;
	scanf("%d",&N);
	int arr[N][N];
	int i,j,k;
	i=0;
	//Input
	while(i<N){
		j=0;
		while(j<N){
			scanf("%d",&arr[i][j]);
			j++;
		}
		i++;
	}
	vector<struct node> Result;
	//Main Code
	i=0;
	struct node Node;
	while(i<N){
		j=0;
		while(j<N){
			if(arr[i][j]!=0){
				Node.C=arr[i][j];
				Node.U=Node.D=i+1;
				Node.L=Node.R=j+1;
				Result.push_back(Node);
			}
			j++;
		}
		i++;
	}
	//Display The Result
	printf("%d\n",(int)Result.size());
	i=0;
	while(i<Result.size()){
		printf("%d %d %d %d %d\n",Result[i].C,Result[i].U,Result[i].D,Result[i].L,Result[i].R);
		i++;
	}
	return 0;
}
