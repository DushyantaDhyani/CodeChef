#include<iostream>
#include<map>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int main(){
	int N,M;
	int i;
	string str;
	scanf("%d %d",&N,&M);
	while(N!=0 && M!=0){
		scanf("%d %d",&N,&M);
		map<string,int> Data;
		vector<int> Temp;
		vector<int>::iterator it1,it2;
		map<string,int>::iterator it;
		i=1;
		while(i<=N){
			cin>>str;
			if((it=Data.find(str))==Data.end()){
				Data.insert(pair<string,int>(str,1));
			}
			else{
				((*it).second)++;
			}
			i++;
		}
		it=Data.begin();
		while(it!=Data.end()){
			Temp.push_back((*it).second);
			it++;
		}
		sort(Temp.begin(),Temp.end());
		i=1;
		it2=Temp.begin();
		while(i<=N){
			it1=lower_bound(it2,Temp.end(),i);
			it2=upper_bound(it1,Temp.end(),i);
			printf("%d\n",(it2-it1));
			i++;
		}
	}
	return 0;
}