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
	pos1=pos2=0;
	while(T>0){
		value=1;
		scanf("%d %d %ld",&L,&R,&M);
		if(L==R){
			printf("%d\n",(arr[L-1]%M));
		}
		else{
			/*if(L<index[pos1]){
				low=0;
			}
			else{
				low=pos1;
			}
			if(R>index[pos2]){
				high=index.size()-1;
			}
			else{
				high=pos2;
			}*/
			low=0;
			high=index.size()-1;
			while(low<=high){
				mid=(low+high)/2;
				if(index[mid]==L){
					pos1=mid;
					break;
				}
				else if(index[mid]>L){
					high=mid-1;
				}
				else if(index[mid]<L && mid+1<=index.size()-1 && index[mid+1]<L){
					low=mid+1;
				}
				else {
					pos1=mid;
					break;
				}
			}
			low=pos1;
			/*
			if(R>index[pos2]){
				high=index.size()-1;
			}
			else{
				high=pos2;
			}*/
			high=index.size()-1;
			//printf("%d %d\n",low,high);
			while(low<=high){
				mid=(low+high)/2;
				if(index[mid]==R){
					pos2=mid;
					break;
				}
				else if(index[mid]>R){
				high=mid-1;
				}
				else if(index[mid]<R && mid+1<=index.size()-1 && index[mid+1]<R){
					low=mid+1;
				}
				else {
					pos2=mid;
					break;
				}
			}
			if(pos1==pos2){
				if(index[pos1]==L){
					value=(value*(Product[pos1]%M))%M;
				}
				else{
				
				}
			}
			else{
				printf("Before %lld\n",value);
				while(R>=index[pos2]){
					value=(value*(arr[R-1]%M))%M;
					R--;
				}
				printf("After %lld\n",value);
				pos2--;
				if(index[pos1]<L){
					pos1++;
					while(pos1<index.size() && L<index[pos1]){
						value=(value*(arr[L-1]%M))%M;
						L++;
					}
				}
				printf("%d %d\n",pos1,pos2);
				while(pos1<=pos2){
					value=(value*(Product[pos1]%M))%M;
					pos1++;
				}
				printf("Answer :");
				printf("%lld\n",value);
			}
			T--;
	}
	return 0;
}

