#define MAX 1000000000000000000
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	int N;
	int L,R;
	int pos1,pos2;
	long M;
	int limit;
	scanf("%d",&N);
	vector<int> arr(N);
	vector<int> index;
	vector<long long> Product;
	int i=1;
	long long Prod;
	Prod=1;
	limit=sqrt(N);
	int count=0;
	index.push_back(1);
	while(i<=N){
		scanf("%d",&arr[i-1]);
		if(count<limit && arr[i-1]<=(MAX/Prod)){
			Prod*=arr[i-1];
			count++;
		}
		else{
			index.push_back(i);
			Product.push_back(Prod);
			Prod=1;
			Prod*=arr[i-1];
			count=1;
		}
		i++;
	}
	Product.push_back(Prod);
	i=0;
	while(i<index.size()){
		printf("%d ",index[i]);
		i++;
	}
	printf("\n");
	
	i=0;
	while(i<Product.size()){
		printf("%lld ",Product[i]);
		i++;
	}
	printf("\n");
	
	int T;
	long long value;
	int low,mid,high;
	scanf("%d",&T);
