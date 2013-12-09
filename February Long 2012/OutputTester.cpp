#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	char arr[N][N];
	memset(arr,'W',sizeof(arr));
	int T;
	int sx,sy,ex,ey,val;
	scanf("%d",&T);
	while(T>0){
		scanf("%d %d %d %d %c",&sx,&sy&ex,&ey,&val);
		j=sy;
		while(j<=ey){
			arr[sx][j]=val;
		}
		T--;
	}
}