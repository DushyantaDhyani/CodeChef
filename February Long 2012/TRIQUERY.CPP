#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int N,Q;
	int i,j;
	int x,y,d;
	scanf("%d %d",&N,&Q);
	map<int,vector<int> > Data;
	map<int,vector<int> >::iterator it,it1;
	vector<int>::iterator itemp,it2,it3,it4;
	i=1;
	while(i<=N){
		scanf("%d %d",&x,&y);
		if((it=Data.find(x))==Data.end()){
			vector<int> Temp;
			Temp.push_back(y);
			Data.insert(pair<int,vector<int> >(x,Temp));
		}
		else{
			(*it).second.push_back(y);
		}
		i++;
	}
	it=Data.begin();
	while(it!=Data.end()){
		sort((*it).second.begin(),(*it).second.end());
		it++;
	}
	j=1;
	int count;
	while(j<=Q){
		count=0;
		scanf("%d %d %d",&x,&y,&d);
		it=lower_bound(Data.begin(),Data.end(),x);
		it1=upper_bound(Data.begin(),Data.end(),x+d)++;
		while(it!=it1){
			it2=lower_bound((*it).second.begin(),(*it).second.end(),y);
			it3=upper_bound((*it).second.begin(),(*it).second.end(),y+d);
			//int num=(*it).first-x;
			//it4=upper_bound((*it).second.begin(),(*it).second.end(),y+d);
			if((it3-it4)<0){
				it3=it4;
			}
			count+=it3-it2;
			it++;
		}
		j++;
	}
	return 0;
}
