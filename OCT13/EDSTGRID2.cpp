//Making Black Cells White
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
typedef struct Node{
	int op;
	int x;
	int y;
};
int main(){
	int T;
	int N,M,C2,C3,i,j,k,c;
	scanf("%d",&T);
	while(T>0){
		scanf("%d %d %d %d",&N,&M,&C2,&C3);
		char Data[N][M+1];
		vector<Node> Answer;
		i=0;
		while(i<N){
			scanf("%s",Data[i]);
			i++;
		}
		i=0;
		while(i<N){
			j=0;
			while(j<M){
				if(Data[i][j]=='B'){
					Node node;
					node.op=3;
					node.x=i+1;
					node.y=j+1;
					Answer.push_back(node);
				}
				j++;
			}
			i++;
		}
		c=Answer.size();
		printf("%d\n",c);
		i=0;
		while(i<c){
			printf("%d %d %d\n",Answer[i].op,Answer[i].x,Answer[i].y);
			i++;
		}
		T--;
	}
	return 0;
}
