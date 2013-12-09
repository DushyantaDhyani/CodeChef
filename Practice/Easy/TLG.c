#define abs(a) (a>0?a:(-1*a))
#include<stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	int num1,num2;
	long score1,score2;
	score1=score2=0;
	long arr[N];
	register int i=0;
	while(i<N){
		scanf("%d %d",&num1,&num2);
		score1+=num1;
		score2+=num2;
		arr[i]=score1-score2;
		i++;
	}
	long max=abs(arr[0]);
	int pos=0;
	i=1;
	while(i<N){
		if(abs(arr[i])>max){
			max=abs(arr[i]);
			pos=i;
		}
		i++;
	}
	if(arr[pos]>0){
		printf("1 %ld\n",max);
	}
	else{
		printf("2 %ld\n",max);
	}
	return 0;
}
