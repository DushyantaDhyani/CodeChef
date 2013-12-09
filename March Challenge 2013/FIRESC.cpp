#define MOD 1000000007
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef struct Node{
	int val1;
	int val2;
};
bool myfunc(Node node1,Node node2){
	if(node1.val2<node2.val2){
		return true;
	}
	return false;
}
int main(){
	int T;
	int N,M;
	int num1,num2;
	int count;
	long ways;
	int i;
	int temp;
	scanf("%d",&T);
	while(T>0){
		ways=1;
		scanf("%d %d",&N,&M);
		count=0;
		vector<Node> Data(M);
		int Arr[N+1];
		i=0;
		while(i<M){
			scanf("%d %d",&(Data[i].val1),&(Data[i].val2));
			if(Data[i].val1>Data[i].val2){
				temp=Data[i].val1;
				Data[i].val1=Data[i].val2;
				Data[i].val2=temp;
			}
			i++;
		}
		sort(Data.begin(),Data.end(),myfunc);
		i=0;
		while(i<=N){
			Arr[i]=i;
			i++;
		}
		i=0;
		while(i<M){
			num1=Data[i].val1;
			num2=Data[i].val2;
			while(Arr[num1]!=num1){
				num1=Arr[num1];
			}
			Arr[num2]=num1;
			i++;
		}
		map<int,int> Map;
		map<int,int>::iterator it;
		i=1;
		while(i<=N){
			if((it=Map.find(Arr[i]))==Map.end()){
				Map.insert(pair<int,int>(Arr[i],1));
				count++;
			}
			else{
				(*it).second++;
			}
			i++;
		}
		it=Map.begin();
		while(it!=Map.end()){
			ways=(ways*((*it).second%MOD))%MOD;
			it++;
		}
		printf("%d %ld\n",count,ways);
		T--;
	}
}