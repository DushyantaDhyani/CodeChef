#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
using namespace std;
int main(){
	int N,Q;
	scanf("%d %d",&N,&Q);
	vector<vector<int> > Data(N);
	vector<int>::iterator it;
	int admin;
	scanf("%d",&admin);
	int i=1;
	int x,y;
	while(i<=(N-1)){
		scanf("%d %d",&x,&y);
		Data[x].push_back(y);
		i++;
	}
	/*
	i=0;
	while(i<N){
		printf("%d ",i);
		it=Data[i].begin();
		while(it!=Data[i].end()){
			printf("-->%d",(*it));
			it++;
		}
		printf("\n|\n");
		i++;
	}
	printf("X\n");
	*/
	int j=1;
	int num;
	int flag;
	while(j<=Q){
		scanf("%d %d",&x,&y);
		flag=0;
		list<int> Queue;
		Queue.push_back(x);
		while(!Queue.empty()){
			num=Queue.front();
			Queue.pop_front();
			it=Data[num].begin();
			while(it!=Data[num].end()){
				if((*it)==y){
					flag=1;
					break;
				}
				else{
					Queue.push_back(*it);
				}
				it++;
			}
			if(flag){
				break;
			}
		}
		if(flag){
			printf("-1\n");
		}
		else{
			flag=0;
			list<int> Queue;
			Queue.push_back(y);
			while(!Queue.empty()){
				num=Queue.front();
				Queue.pop_front();
				it=Data[num].begin();
				while(it!=Data[num].end()){
					if((*it)==x){
						flag=1;
						break;
					}
					else{
						Queue.push_back(*it);
					}
					it++;
				}
				if(flag){
					break;
				}
			}
			if(flag){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
		j++;
	}
	
	return 0;
}