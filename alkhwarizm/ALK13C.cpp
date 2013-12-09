#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Node{
	int x;
	int y;
};
bool myfunc1(Node node1,Node node2){
	return node1.x>node2.x ? true: false;
}
bool myfunc2(Node node1,Node node2){
	return node1.y>node2.y ? true: false;
}
int main(){
	int T,N,i;
	long answer;
	int count1,count2;
	scanf("%d",&T);
	int x,y;
	while(T>0){
		answer=0;
		scanf("%d",&N);
		vector<Node> Data(N);
		i=0;
		while(i<N){
			scanf("%d",&x,&y);
			Node node;
			node.x=x;
			node.y=y;
			Data[i]=node;
			i++;
		}
		sort(Data.begin(),Data.end(),myfunc1);
		i=0;
		while(i<Data.size()){
			printf("%d %d\n",Data[i].x,Data[i].y);
			i++;
		}
		count1=count2=1;
		i=1;
		while(i<N){
			if( (Data[i].x) != (Data[i-1].x)){
				count1++;
			}
			i++;
		}
		sort(Data.begin(),Data.end(),myfunc2);
		i=0;
		while(i<Data.size()){
			printf("%d %d\n",Data[i].x,Data[i].y);
			i++;
		}
		i=1;
		while(i<N){
			if( (Data[i].y) != (Data[i-1].y)){
				count2++;
			}
			i++;
		}
		//printf("%d %d\n",count1,count2);
		answer=(count1+1)*(count2+1);
		printf("%ld\n",answer);
		T--;
	}
	return 0;
}
