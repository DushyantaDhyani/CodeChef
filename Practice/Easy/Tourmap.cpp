#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;
typedef struct Node{
	string city1;
	string city2;
	int cost;
};
int main(){
	int T,N;
	char *ptr;
	scanf("%d",&T);
	int i;
	Node node1;
	string temp;
	while(T>0){
		scanf("%d",&N);
		i=1;
		while(i<N){
			cin>>node1.city1>>node1.city2;
			scanf("%s$",ptr);
			node1.cost=atoi(ptr);
			i++;
		}
		i=0;
		while(i<(N-2)){
			j=i+1;
			while(j<(N-1)){
				if(Arr[i].b==Arr[j].a){
					
				}
			}
		}
		T--;
	}
}