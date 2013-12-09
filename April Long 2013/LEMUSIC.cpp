#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int T;
	int N;
	int i;
	int count;
	long num1,num2;
	long long int Total;
	scanf("%d",&T);
	while(T>0){
		scanf("%d",&N);
		map<long,long long int> Data;
		vector<long long int> Temp;
		map<long,long long int>::iterator it;
		vector<long long int>::iterator Tempit;
		i=1;
		while(i<=N){
			cin>>num1>>num2;
			if((it=Data.find(num1))==Data.end()){
				Data.insert(pair<long,long long int>(num1,num2));
			}
			else{
				(*it).second+=num2;
			}
			i++;
		}
		count=1;
		Total=0;
		it=Data.begin();
		while(it!=Data.end()){
			Temp.push_back(((*it).second));
			it++;
		}
		sort(Temp.begin(),Temp.end());
		Tempit=Temp.begin();
		while(Tempit!=Temp.end()){
            Total+=count*(*Tempit);
            count++;
            Tempit++;
		}
		cout<<Total<<endl;
		T--;
	}
	return 0;
}
