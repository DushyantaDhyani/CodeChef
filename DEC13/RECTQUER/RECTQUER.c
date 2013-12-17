#include<stdio.h>
#include<string.h>
int main(){
	int N,i,j,k;
	int Q;
	int x1,y1,x2,y2;
	scanf("%d",&N);
	short arr[N][N],
	int temp[N][N][10];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%hd",&arr[i][j]);
			memset(temp[i][j],0,sizeof(temp[i][j]);
			k=0;
			while(k<10){
				printf("%d ",temp[i][j][k]);
				k++;
			}
			printf("\n");
		}
		printf("\n");
	}
	scanf("%d",Q);
	while(Q>0){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		Q--;
	}
	return 0;
}
