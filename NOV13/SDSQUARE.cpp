#define MAX 10000000000
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<long long> Squares;
vector<long long>::iterator lb,ub;
int check(long long num){
	int digit;
	while(num>0){
		digit=num%10;
		if(!(digit==0 || digit==1 || digit==4 ||digit==9)){
			return 0;
		}
		num=num/10;
	}
	return 1;
}
void preprocess(){
	long long limit=sqrt(MAX);
	long long i=1;
	while(i<=limit){
		if(check((i*i))){
			Squares.push_back(i*i);
		}
		i++;
	}
}
int main(){
	preprocess();
	int T;
	long long a,b;
	scanf("%d",&T);
	while(T>0){
		scanf("%lld %lld",&a,&b);
		lb=lower_bound(Squares.begin(),Squares.end(),a);
		ub=upper_bound(Squares.begin(),Squares.end(),b);
		printf("%d\n",(ub-lb));
		T--;
	}
	return 0;
}
