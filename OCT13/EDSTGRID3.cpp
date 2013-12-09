//Performing Operation 1 & 2 Both
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
	int N,M,C2,C3,i,j,k,c1,c2;
	scanf("%d",&T);
	while(T>0){
		scanf("%d %d %d %d",&N,&M,&C2,&C3);
		char Data[N][M+1],Result[N][M+1];
		vector<Node> Answer1,Answer2;
		i=0;
		while(i<N){
			scanf("%s",Data[i]);
			memset(Result[i],'W',M*sizeof(char));
			Result[i][M]='\0';
			i++;
		}
		i=0;
		while(i<N){
			j=0;
			while(j<M){
				if(Data[i][j]=='B'){
					k=0;
					while(k<M){
						if(Result[i][k]!='B'){
							if(Data[i][k]!='B'){
								Node node;
								node.op=2;
								node.x=i+1;
								node.y=k+1;
								Answer1.push_back(node);
								Result[i][k]='B';	
							}
							else{
								Result[i][k]='B';
							}
						}
						k++;
					}
					break;		
				}
				j++;
			}
			i++;
		}
		i=0;
		while(i<M){
			j=0;
			while(j<N){
				if(Data[j][i]=='B'){
					k=0;
					while(k<N){
						if(Result[k][i]!='B'){
							if(Data[k][i]!='B'){
								Node node;
								node.op=2;
								node.x=k+1;
								node.y=i+1;
								Answer1.push_back(node);
								Result[k][i]='B';	
							}
							else{
								Result[k][i]='B';
							}
						}
						k++;
					}
					break;
				}
				j++;
			}
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
					Answer2.push_back(node);
				}
				j++;
			}
			i++;
		}
		
		
		c1=Answer1.size();
		c2=Answer2.size();
		if((c1*C2)<(c2*C3)){
			printf("%d\n",c1);
			i=0;
			while(i<c1){
				printf("%d %d %d\n",Answer1[i].op,Answer1[i].x,Answer1[i].y);
				i++;
			}
		}
		else{
			printf("%d\n",c2);
			i=0;
			while(i<c2){
				printf("%d %d %d\n",Answer2[i].op,Answer2[i].x,Answer2[i].y);
				i++;
			}
		}
		T--;
	}
	return 0;
}
