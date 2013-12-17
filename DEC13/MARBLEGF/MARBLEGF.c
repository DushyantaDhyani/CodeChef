#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
long long tree[2100000];
int arr[1000000];
long long  size;
void setTree(long long  node, int begin,int end){
	if(begin==end){
		tree[node-1]=arr[begin];
	}
	else{
		setTree(2*node,begin,(begin+end)/2);
		setTree(2*node+1,(begin+end)/2+1,end);
		tree[node-1]=tree[2*node-1]+tree[2*node];
	}
}
long long getSum(long long  node,int begin,int end,int i,int j){
	long long p1,p2;
	if(i>end || j<begin){
		return 0;
	}
	if(begin>=i && end<=j){
		return tree[node-1];
	}
	p1=getSum(2*node,begin,(begin+end)/2,i,j);
	p2=getSum(2*node+1,(begin+end)/2+1,end,i,j);
	return (p1+p2);
}
void changeTree(long long  node, int begin,int end,int i,long long  value){
	if(begin==end && begin==i){
		tree[node-1]+=value;
		return;
	}
	if(begin<=i && i<=end ){
		tree[node-1]+=value;
		changeTree(2*node,begin,(begin+end)/2,i,value);
		changeTree(2*node+1,(begin+end)/2+1,end,i,value);
	}
}
int main(){ 
	int i=0;
	int N,Q,j;
	scanf("%d %d",&N,&Q);
	char ch;
	long long num_marbles; 
	int index;
	size=2*pow(2,(ceil(log(N)/log(2))))-1;
	i=0;
	while(i<N){
		scanf("%d",&arr[i]);
		i++;
	}
	setTree(1,0,N-1);
	i=1;
	while(i<=Q){
		fflush(stdin);
		scanf(" %c %d %lld",&ch,&index,&num_marbles);
		if(ch=='S'){
			printf("%lld\n",getSum(1,0,N-1,index,num_marbles));
		}
		else if(ch=='G'){
			changeTree(1,0,N-1,index,num_marbles);
		}
		else if(ch=='T'){
			changeTree(1,0,N-1,index,(-1*num_marbles));
		}
		i++;
	}
	return 0;
}
