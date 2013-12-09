#define MAX 1000000
#include<stdio.h>
int flag[1000000+1]
void setFlags(){
	int i,j;
    for(i=1;i<=MAX;i++){
       	 flag[i] = 1;
    }
    for(i=2;i<=(int)sqrt(MAX);i++) {
        if (flag[i]) {
                for(j=i;j*i<MAX;j++){
                	 flag[i*j] = 0;
                }
        }
	}
}
int main(){
	int T;
	scanf("%d",&T);
	long P;
	while(T>0{
		scanf("%ld",&P);
		if(findFactors(P)==3){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		T--;
	}
	return 0;
}