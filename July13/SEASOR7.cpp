#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int T,N,K;
    int i;
    scanf("%d",&T);
    while(T>0){
    	  scanf("%d %d",&N,&K);
    	  vector<int> arr1(N);
    	  vector<int> arr2(N);
    	  vector<int> dump(N);
    	  vecotr<int>::iterator it1,it2,it3,it4,start,last;
    	  i=0;
    	  while(i<N){
    	  	scanf("%d",&arr1[i]);
    	  	dump[i]=arr2[i]=arr1[i];
    	  	i++;
    	  }
    	  sort(dump.begin(),dump.end());
    	  start=dump.begin();
    	  last=dump.end();
    	  it1=arr1.begin();
    	  it2=arr1.end();
    	  while(it1<it2 && start<last){
    	  	if((*it1)==(*start)){
    	  		it1++;
    	  		start++;
    	  	}
    	  	else{
    	  		break;
    	  	}
    	  }
    	  while((it2-1)>=it1 && (last-1)>=first){
    	  	if((*it2)==(*(last-1))){
    	  		it2--;
    	  		last--;
    	  	}
    	  	else{
    	  		break;
    	  	}
    	  }
    	  it3=it1;
    	  while(
          T--;
    }
    return 0;
}
