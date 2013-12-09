#include<stdio.h>
int main(){
	int T;
	double D,R;
	int U,N,M,C;
	double Cost,temp;
	int i;
	int pos;
	scanf("%d",&T);
	while(T>0){
		scanf("%lf %d %d",&D,&U,&N);
		Cost=D*U;
		pos=0;
		i=1;
		while(i<=N){
			scanf("%d %lf %d ",&M,&R,&C);
			temp=U*R+C*1.0/M;
			if(temp<Cost){
				Cost=temp;
				pos=i;
			}
			i++;
		}
		printf("%d\n",pos);
		T--;
	}
	return 0;
}
