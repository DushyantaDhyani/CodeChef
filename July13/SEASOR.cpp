#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main(){
	int T,N,K;
	int i;
	scanf("%d",&T);
	while(T>0){
		map<int,int> Data;
		map<int,int>::iterator it;
		scanf("%d %d",&N,&K);
		vector<long> arr(N);
		vector<long>::iterator it1,it2,it3,start;
		vector<int> Result;
		i=0;
		while(i<N){
			scanf("%ld",&arr[i]);
			if((it=Data.find(arr[i]))!=Data.end()){
				(*it).second++;
			}
			else{
				Data[arr[i]]=1;
			}
			i++;
		}
		it1=arr.begin();
		it2=arr.end();
		while(it1<(arr.end()-1) && *(it1)<=*(it1+1)){
			it1++;
		}
		while(it1!=it2){
			start=max_element(it1,it2);
			while(start!=(it2-1)){
				it3=start+K;
				if(it3>it2){
					it3=it2;
				}
				sort(start,it3);
				Result.push_back((start-arr.begin()+1));
				start=it3-1;
			}
		}
		printf("%d\n",(int)Result.size());
		i=0;
		while(i<Result.size()){
			printf("%d ",Result[i]);
			i++;
		}
		printf("\n");
		T--;
	}
	return 0;
}
