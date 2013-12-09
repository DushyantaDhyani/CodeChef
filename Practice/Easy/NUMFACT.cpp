#define MAX 1001
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
vector<int> Prime;
int arr[MAX];
void preprocess(){
	memset(arr,0,sizeof(arr));
	int i,j;
	arr[0]=arr[1]=1;
	i=2;
	int limit=(int)sqrt(MAX);
	while(i<=limit){
		if(!arr[i]){
			Prime.push_back(i);
			j=i*i;			
			while(j<MAX){
				arr[j]=1;
				j+=i;
			}
		}
		i++;
	}
	while(i<MAX){
		if(!arr[i]){
			Prime.push_back(i);
		}
		i++;
	}
}
int main(){
	int T;
	int N;
	int i;
	int j;
	preprocess();
	scanf("%d",&T);
	int num;
	int Total;
	while(T>0){
		Total=1;
		map<int,int> Data;
		map<int,int>::iterator it;
		scanf("%d",&N);
		int numbers[N];
		i=1;
		while(i<=N){
			scanf("%d",&numbers[i-1]);
			i++;
		}
		i=1;
		while(i<=N){
			num=numbers[i-1];
			j=0;
			while(j<Prime.size()){
				if((num%Prime[j])==0){
					if((it=Data.find(Prime[j]))==Data.end()){
						Data[Prime[j]]=1;
					}
					else{
						(*it).second++;
					}
					num=num/Prime[j];
				}
				else{
					j++;
				}
			}
			i++;
		}
		it=Data.begin();
		while(it!=Data.end()){
			Total*=(*it).second +1;
			it++;
		}
		printf("%d\n",Total);
		T--;
	}
	return 0;
}
