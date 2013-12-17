#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
struct node{
	int val;
	int arr[10];
};
int main(){
	int N,i,j,k;
	int x1,y1,x2,y2;
	int Q;
	int count;
	int val,temp;
	int Result[10];
	scanf("%d",&N);
	vector< vector<struct node> > Data(N);
	i=0;
	while(i<N){
		Data[i].resize(N);
		j=0;
		while(j<N){
			scanf("%d",&val);
			Data[i][j].val=val;
			memset(Data[i][j].arr,0,sizeof(int)*10);
			if(i!=0){
				memcpy(Data[i][j].arr,Data[i-1][j].arr,sizeof(int)*10);
			}
			if(j!=0){
				k=0;
				while(k<j){
					if((temp=Data[i][k].val)==10){
						Data[i][j].arr[0]++;
					}
					else{
						Data[i][j].arr[temp]++;
					}
					k++;
				}
			}
			
			if(val==10){
				Data[i][j].arr[0]++;
			}
			else{
				Data[i][j].arr[val]++;
			}
			j++;
		}
		i++;
	}
	/*
	i=0;
	while(i<N){
		j=0;
		while(j<N){
			k=0;
			while(k<10){
				printf("%d ",Data[i][j].arr[k]);
				k++;
			}
			printf("\n");
			j++;
		}
		printf("\n");
		i++;
	}*/
	scanf("%d",&Q);
	while(Q>0){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		//printf("You entered as query %d %d %d %d\n",x1,y1,x2,y2);
		x1--;y1--;x2--;y2--;
		memcpy(Result,Data[x2][y2].arr,sizeof(int)*10);
		if(y1!=0){
			k=0;
			while(k<10){
				Result[k]-=Data[x2][y1-1].arr[k];
				k++;
			}
		}
		if(x1!=0){
			k=0;
			while(k<10){
				Result[k]-=Data[x1-1][y2].arr[k];
				k++;
			}
		}
		if(x1!=0 && y1!=0){
			k=0;
			while(k<10){
				Result[k]+=Data[x1-1][y1-1].arr[k];
				k++;
			}
		}
		count=0;
		k=0;
		while(k<10){
			if(Result[k]>0){
				count++;
			}
			k++;
		}
		printf("%d\n",count);
		Q--;
	}
	return 0;
}
