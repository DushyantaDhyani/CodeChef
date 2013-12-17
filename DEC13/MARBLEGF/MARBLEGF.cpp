#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
int size;
void setTree(int node, int begin,int end, int tree[size],int N,int arr[]){
	if(begin==end){
		tree[node-1]=arr[begin];
	}
	else{
		setTree(2*node,begin,(begin+end)/2,tree,N,arr);
		setTree(2*node+1,(begin+end)/2+1,end,tree,N,arr);
		tree[node-1]=tree[2*node-1]+tree[2*node];
	}
}
int getSum(int node,int begin,int end,int tree[size],int arr[],int i,int j){
	int p1,p2;
	if(i>end || j<begin){
		return 0;
	}
	if(begin>=i && end<=j){
		return tree[node-1];
	}
	p1=getSum(2*node,begin,(begin+end)/2,tree,arr,i,j);
	p2=getSum(2*node+1,(begin+end)/2+1,end,tree,arr,i,j);
	return (p1+p2);
}
void changeTree(int node, int begin,int end, int tree[],int arr[],int i,int value){
	if(begin<=i && i<=end ){
		tree[node-1]+=value;
		changeTree(2*node,begin,(begin+end)/2,tree,arr,i,value);
		changeTree(2*node+1,(begin+end)/2+1,end,tree,arr,i,value);
	}
}
int main(){
	int N,Q;
	scanf("%d %d",&N,&Q);
	int arr[N];
	char ch;
	int index,num_marbles; 
	size=2*pow(2,(ceil(log(N))+1));
	int segtree[size];
	memset(segtree,0,sizeof(segtree));
	int i=0;
	while(i<N){
		scanf("%d",&arr[i]);
		i++;
	}
	setTree(1,0,N-1,segtree,N,arr);
	i=1;
	while(i<=Q){
		scanf("%c %d %d",&ch,&index,&num_marbles);
		printf("%d %c %d %d\n",i,ch,index,num_marbles);
		/*if(ch=='S'){
			printf("%d\n",getSum(1,0,N-1,segtree,arr,index,num_marbles));
		}
		else if(ch=='G'){
			changeTree(1,0,N-1,segtree,arr,index,num_marbles);
		}
		else if(ch=='T'){
			changeTree(1,0,N-1,segtree,arr,index,(-1*num_marbles));
		}
		else{
			printf("Ye Enter Hua hai %d for i=%d \n",ch,i);
		}
		switch(ch){
			case 'S':{
					printf("%d\n",getSum(1,0,N-1,segtree,arr,index,num_marbles));
					break;
				 }
			case 'G':{
					changeTree(1,0,N-1,segtree,arr,index,num_marbles);
					break;
				 }
			case 'T':{
					changeTree(1,0,N-1,segtree,arr,index,(-1*num_marbles));
					break;
				 }
			default:{
					printf("Ye Enter Hua hai %c for i=%d \n",ch,i);
				}
		}*/
		i++;
	}
	return 0;
}
