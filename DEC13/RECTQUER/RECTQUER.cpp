#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
vector< vector <short> > Data;
vector< vector <int> >Tree;
int temp;
void setTree(int node, int begin,int end,int index){
	if(begin==end){
		temp=Data[index][begin];
		if(temp==10){
			temp=pow(2,0);
		}
		else{
			temp=pow(2,temp);
		}
		Tree[index][node-1]=temp;
	}
	else{
		setTree(2*node,begin,(begin+end)/2,index);
		setTree(2*node+1,(begin+end)/2+1,end,index);
		Tree[index][node-1]=Tree[index][2*node-1] | Tree[index][2*node];
	}
}
int getCount(int node,int begin,int end,int i,int j,int index){
	int p1,p2;
	if(i>end || j<begin){
		return 0;
	}
	if(begin>=i && end<=j){
		return Tree[index][node-1];
	}
	p1=getCount(2*node,begin,(begin+end)/2,i,j,index);
	p2=getCount(2*node+1,(begin+end)/2+1,end,i,j,index);
	return (p1|p2);
}
int main(){
	int N,Q;
	int i,j;
	int x1,y1,x2,y2;
	int size;
	int result,count;
	scanf("%d",&N);
	Data.resize(N);
	Tree.resize(N);
	size=pow(2,(1+(int)ceil(log(N)/log(2))))-1;
	i=0;
	while(i<N){
		Data[i].resize(N);
		Tree[i].resize(size);
		j=0;
		while(j<N){
			scanf("%hd",&Data[i][j]);
			j++;
		}
		j=0;
		while(j<size){
			Tree[i][j]=0;
			j++;
		}
		setTree(1,0,N-1,i);
		i++;
	}
	scanf("%d",&Q);
	while(Q>0){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		x1--;x2--;y1--;y2--;
		i=x1;
		result=0;
		while(i<=x2){
			result=result | getCount(1,0,N-1,y1,y2,i) ;
			i++;	
		}
		count=0;
		while(result>0){
			if ( (result & 1)==1){
				count++;
			}
			result=result>>1;
		}
		printf("%d\n",count);
		Q--;
	}
	return 0;
}
