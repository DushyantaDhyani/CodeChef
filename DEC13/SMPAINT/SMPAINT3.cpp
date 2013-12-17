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
	while(i<N){
		j=0;
		while(j<N){
			scanf("%d",&arr[i][j]);
			j++;
		}
		i++;
	}
	vector<struct node> Result;
	struct node Node;
	i=0;
	j=0;
	int color;
	while(j<N){
		color=-1;
		i=0;
		while(i<N){
			k=i;
			while(k<N){
				if(arr[k][j]==0){
					if(color!=-1){
						Node.C=color;
						Node.U=i+1;Node.D=k;Node.L=j+1;Node.R=j+1;
						Result.push_back(Node);
						i=k;
						color=-1;
						break;
					}
					else{
						k++;
					}
				}
				else {
					if(color==-1){
						i=k;
						color=arr[k][j];
						k++;
					}
					else if(arr[k][j]==color){
						k++;
					}
					else{
						Node.C=color;
						Node.U=i+1;Node.D=k;Node.L=j+1;Node.R=j+1;
						Result.push_back(Node);
						i=k;
						color=-1;
						break;
					}
				}
			}
			if(k==N){
				if(color!=-1){
					Node.C=color;
					Node.U=i+1;
					Node.D=k;
					Node.L=j+1;Node.R=j+1;
					Result.push_back(Node);
				}
				i=k;
			}
		}
		j++;
	}
	printf("%d\n",(int)Result.size());
	i=0;
	while(i<Result.size()){
		printf("%d %d %d %d %d\n",Result[i].C,Result[i].U,Result[i].D,Result[i].L,Result[i].R);
		i++;
	}
	return 0;
}
