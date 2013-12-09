#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	long arr1[N];
	long arr2[N];
	int i=0;
	set<long> Data;
	set<long>::iterator it;
	while(i<N){
		scanf("%ld",&arr1[i]);
		arr2[i]=arr1[i];
		i++;
	}
	Data.insert(arr2,arr2+N);
	int offset=1;
	while(offset!=(N)){
		i=0;
		while(i<(N-offset)){
			arr2[i]+=arr1[i+offset];
			i++;
		}
		Data.insert(arr2,arr2+i);
		offset++;
	}
	it=Data.begin();
	while(it!=Data.end()){
		printf("%ld ",(*it));
		it++;
	}
	printf("\n");
	printf("%d\n",((int)Data.size()-1));
	return 0;
}
