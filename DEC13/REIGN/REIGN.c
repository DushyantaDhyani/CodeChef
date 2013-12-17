#include<stdio.h>
#include<limits.h>
long long max(long long num1,long long num2){
	return (num1>num2?num1:num2);
}
int main(){
	int N,K;
	int T;
	int i;
	scanf("%d",&T);
	long long sum,temp;
	while(T>0){
		scanf("%d %d",&N,&K);
		long long arr[N];
		long long start[N];
		long long end[N];
		i=0;
		while(i<N){
			scanf("%lld",&arr[i]);
			i++;
		}
		//Setting The value of maximum sum of subset ending at index i
		end[0]=arr[0];
		i=1;
		sum=arr[0]<0?0:arr[0];
		while((i+K+1)<N){
			sum+=arr[i];
			if(arr[i]>(temp=max(sum,end[i-1]))){
				end[i]=arr[i];
			}
			else{
				end[i]=temp;
			}
			if(sum<0){
				sum=0;
			}
			i++;
		}
		start[N-1]=arr[N-1];
		i=N-2;
		sum=arr[N-1]<0?0:arr[N-1];
		while((i-K-1)>0){
			sum+=arr[i];
			if(arr[i]>(temp=max(sum,start[i+1]))){
				start[i]=arr[i];
			}
			else{
				start[i]=temp;
			}
			if(sum<0){
				sum=0;
			}
			i--;
		}
		i=1;
		sum=LONG_MIN;
		while((i+K+1)<=N){
			if(sum<(temp=(end[i-1]+start[i+K]))){
				sum=temp;
			}
			i++;
		}
		printf("%lld\n",sum);
		T--;
	}
	return 0;
}
