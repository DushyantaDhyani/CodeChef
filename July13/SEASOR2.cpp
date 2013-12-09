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
    		scanf("%d %d",&N,&K);
		vector<long> arr(N);
    		vector<long> Dump(N);
    		vector<long>::iterator it1,it2,it3,start,last;
    		vector<int> Result;
    		i=0;
    		while(i<N){
    			scanf("%ld",&arr[i]);
    			Dump[i]=arr[i];
    			i++;
    		}
    		sort(Dump.begin(),Dump.end());
    		it1=arr.begin();
    		it3=Dump.begin();
    		while(it1!=arr.end() && it3!=Dump.end() && ((*it1)==(*it3))){
    			it1++;
    			it3++;
    		}
    		it2=arr.end();
    		last=Dump.end();
    		while((it2-1)>=arr.begin() && (last-1)>=Dump.begin() && (*(it2-1))== (*(last-1)) ){
    			it2--;
    			last--;
    		}
    		int element;
    		while(it1!=arr.end() && it1!=it2){
    			start=find(it1,it2,*(last-1));
    			while(start!=(it2-1)){
    				it3=start+K;
    				if(it3>it2){
    					it3=it2;
    				}
    				sort(start,it3);
    				Result.push_back((start-arr.begin()+1));
    				start=it3-1;
    			}
    			it2--;
    			last--;
    			while(it1!=it2 && it1!=arr.end() && ((*it1)==(*it3))){
    				it1++;
    				it3++;
    			}
    			while((it2-1)>=arr.begin() && (last-1)>=Dump.begin() && *(it2-1)== *(last-1) ){
    				it2--;
    				last--;
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
