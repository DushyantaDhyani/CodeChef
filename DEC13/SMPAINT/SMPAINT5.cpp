#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int C;
	int U,D,L,R;
};
bool myfunc(struct node Node1,struct node Node2){
	if(Node1.U<Node2.U){
		return true;
	}
	else if(Node1.U>Node2.U){
		return false;
	}
	else{
		if(Node1.L<Node2.L){
			return true;
		}
		else{
			return false;
		}
	}
}
void setResult(vector<struct node>& Result){
	vector<struct node>::iterator it,it1;
	it=Result.begin();
	while(it!=Result.end()){
		it1=it+1;
		while(it1!=Result.end()){
			if((*it).C==(*it1).C){
				if(((*it).L==(*it1).L) && ((*it).R==(*it1).R)){
					(*it).D=(*it1).D;
					Result.erase(it1);
				}
				else{
					it1++;
				}
			}
			else{
				it1++;
			}
		}
		it++;
	}
}
int main(){
	int N;
	scanf("%d",&N);
	int arr[N][N];
	int i,j,k;
	i=0;
	while(i<N){
		j=0;
		while(j<N){
			scanf("%d",&arr[i][j]);
			j++;
		}
		i++;
	}
	vector<struct node> Result1,Result2;
	struct node Node;
	i=0;
	int color;
	while(i<N){
		color=-1;
		j=0;
		while(j<N){
			k=j;
			while(k<N){
				if(arr[i][k]==0){
					if(color!=-1){
						Node.C=color;
						Node.U=i+1;Node.D=i+1;Node.L=j+1;Node.R=k;
						Result1.push_back(Node);
						j=k;
						color=-1;
						break;
					}
					else{
						k++;
					}
				}
				else {
					if(color==-1){
						j=k;
						color=arr[i][k];
						k++;
					}
					else if(arr[i][k]==color){
						k++;
					}
					else{
						Node.C=color;
						Node.U=i+1;Node.D=i+1;Node.L=j+1;Node.R=k;
						Result1.push_back(Node);
						j=k;
						color=-1;
						break;
					}
				}
			}
			if(k==N){
				if(color!=-1){
					Node.C=color;
					Node.U=Node.D=i+1;
					Node.L=j+1;Node.R=k;
					Result1.push_back(Node);
				}
				j=k;
			}
		}
		i++;
	}
	sort(Result1.begin(),Result1.end(),myfunc);
	j=0;
	while(j<N){
		color=-1;
		i=0;
		while(i<N){
			k=i;
			while(k<N){
				if(arr[k][j]==0){
					if(color!=-1){
						Node.C=color;
						Node.U=i+1;Node.D=k;Node.L=j+1;Node.R=j+1;
						Result2.push_back(Node);
						i=k;
						color=-1;
						break;
					}
					else{
						k++;
					}
				}
				else {
					if(color==-1){
						i=k;
						color=arr[k][j];
						k++;
					}
					else if(arr[k][j]==color){
						k++;
					}
					else{
						Node.C=color;
						Node.U=i+1;Node.D=k;Node.L=j+1;Node.R=j+1;
						Result2.push_back(Node);
						i=k;
						color=-1;
						break;
					}
				}
			}
			if(k==N){
				if(color!=-1){
					Node.C=color;
					Node.U=i+1;
					Node.D=k;
					Node.L=j+1;Node.R=j+1;
					Result2.push_back(Node);
				}
				i=k;
			}
		}
		j++;
	}
	sort(Result2.begin(),Result2.end(),myfunc);
	i=0;
		while(i<Result1.size()){
			printf("%d %d %d %d %d\n",Result1[i].C,Result1[i].U,Result1[i].D,Result1[i].L,Result1[i].R);
			i++;
		}
	setResult(Result1);
	setResult(Result2);
	if(Result1.size()<Result2.size()){
		printf("%d\n",(int)Result1.size());
		i=0;
		while(i<Result1.size()){
			printf("%d %d %d %d %d\n",Result1[i].C,Result1[i].U,Result1[i].D,Result1[i].L,Result1[i].R);
			i++;
		}
	}
	else{
		printf("%d\n",(int)Result2.size());
		i=0;
		while(i<Result2.size()){
			printf("%d %d %d %d %d\n",Result2[i].C,Result2[i].U,Result2[i].D,Result2[i].L,Result2[i].R);
			i++;
		}
	}
	return 0;
}
