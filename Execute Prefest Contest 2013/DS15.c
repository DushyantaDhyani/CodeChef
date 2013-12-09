#include<stdio.h>
#include<math.h>                
int main(){
	int T,N;
	int Total;
	int limit,i;
	scanf("%d",&T);
	while(T>0){
		scanf("%d",&N);
		limit=sqrt(N);
		Total=1;
		i=2;
		while(i<=limit){
			if(N%i==0){
				Total+=i+(N/i);
			}
			i++;
		}
		printf("%d\n",Total);
		T--;
	}
	return 0;
}