#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
typedef struct node{
	int x;
	int y;
};
int main(){
	int N;
	scanf("%d",&N);
	vector<int> arr(N);
	vector<int>::iterator it1,it2;
	int i=0;
	int j;
	while(i<N){
		scanf("%d",&arr[i]);
		i++;
	}
	vector<node> Data;
	it1=arr.begin();
	i=0;
	while(it1!=arr.end()){
		it2=arr.end()-1;
		j=arr.size()-1;
		while((it2!=it1) && (*it2 != *it1)){
			it2--;
			j--;
		}
		if(it2!=it1){
			if(2*j-i > arr.size()){
				node Node;
				Node.x=i+1;
				Node.y=j+1;
				Data.push_back(Node);
				arr.erase(it2);
				arr.erase(it1);
			}
			else{
				node Node;
				Node.x=i+1;
				Node.y=arr.size();
				Data.push_back(Node);
				arr.erase(it1);
			}
		}
		else{
			node Node;
			Node.x=i+1;
			Node.y=arr.size();
			Data.push_back(Node);
			arr.erase(it1);
		}
	}
	printf("%d\n",Data.size());
	i=0;
	while(i<Data.size()){
		printf("%d %d\n",Data[i].x,Data[i].y);
		i++;
	}
	return 0;
}
