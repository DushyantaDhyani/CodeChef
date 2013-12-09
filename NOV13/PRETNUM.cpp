#define MAX 1000000000000
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int> Primes;
vector<int>::iterator it1,it2;
bool Flag[1000001];
void preprocess(){
	Flag[0]=Flag[1]=true;
	int limit=sqrt(1000001);
	int i=2,j;
	while(i<=limit){
		if(!Flag[i]){
			Primes.push_back(i);
			j=i*i;
			while(j<1000001){
				Flag[j]=true;
				j+=i;
			}	
		}
		i++;
	}
	while(i<1000001){
		if(!Flag[i]){
			Primes.push_back(i);
		}
		i++;
	}
}
int getPrimeCount(long long L,long long R){
	if(L==1){
		L++;
	}
	int limit=sqrt(R);
	int size=R-L+1;
	int flag[size];
	memset(flag,0,sizeof(flag));
	int i=0;
	long long j;
	while(i<Primes.size() && Primes[i]<=limit){
		j=(L/Primes[i])*Primes[i];
		if(j<L){
			j=j+Primes[i];
		}
		if(j==Primes[i]){
			j+=Primes[i];
		}
		while(j<=R){
			flag[j-L]=1;
			j+=Primes[i];
		}
		i++;
	}
	int PrimeCount=0;
	i=0;
	while(i<size){
		if(flag[i]==0){
			PrimeCount++;
			//printf("%lld\n",(L+i));
		}
		i++;
	}
	return PrimeCount;
}
int main(){
	preprocess();
	int T,i,j;
	int low,high;
	long long L,R;
	int count;
	scanf("%d",&T);
	while(T>0){
		count=0;
		scanf("%lld %lld",&L,&R);
		count+=getPrimeCount(L,R);
		//printf("First Count %d\n",count);
		i=0;
		while(i<Primes.size() && Primes[i]<=R){
			low=ceil(log(L)/log(Primes[i]));
			high=floor(log(R)/log(Primes[i]));
			if(low==0 || low==1){
				low=2;
			}
			//printf("%d %d\n",low,high);
			while(low<=high){
				if(binary_search(Primes.begin(),Primes.end(),(low+1))){
					count++;
				}
				low++;
			}
			i++;
		}
		printf("%d\n",count);
		T--;
	}
	return 0;
}
