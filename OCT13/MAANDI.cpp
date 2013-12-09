#define MAX 32000
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
bool check(long num){
	long lucky=0;
	long overlucky=0;
	int r;
	while(num>0){
		r=num%10;
		if(r==7 || r==4){
			return true;
		}
		num=num/10;
	}
	return false;
}
int main(){
	int T;
	long N;
	long limit;
	int count;
	int i;
	scanf("%d",&T);
	while(T>0){
		scanf("%ld",&N);
		count=0;
		limit=sqrt(N);
		i=1;
		while(i<=limit){
			if((N%i==0)){
				if(check(i)){
					count++;
				}
				if((N/i)!=i){
					if(check(N/i)){
						count++;
					}
				}
			}
			i++;
		}
		printf("%d\n",count);
		T--;
	}
	return 0;
}
