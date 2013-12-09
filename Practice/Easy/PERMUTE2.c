#include<stdio.h>
int main(){
	int flag;
	int num;
	while(1){
		int N;
		flag=0;
		scanf("%d",&N);
		if(N==0){
			break;
		}
		int i=0;
		while(i<N){
			scanf("%d",num);
			if(num!=(i+1)){
				flag=1;
			}
			i++;
		}
		if(flag){
			printf("not ambiguous\n");
		}
		else{
			printf("ambiguous\n");
		}
	}
	return 0;
}