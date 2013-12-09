#define MAX 10001
#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
bool FLAG[MAX];
vector<int> Prime;
vector<int> SemiPrime ;
void setPrimes(){
	int i=0;
	int j;
	while(i<MAX){
		FLAG[i]=true;
		i++;
	}
	FLAG[0]=FLAG[1]=false;
	int limit=sqrt(MAX);
	i=2;
	while(i<=limit){
		if(FLAG[i]){
			Prime.push_back(i);
			j=i*i;
			while(j<MAX){
				FLAG[j]=false;
				j+=i;
			}
		}
		i++;
	}
	while(i<MAX){
        if(FLAG[i]){
            Prime.push_back(i);
        }
        i++;
	}
}
void setSemiPrime(){
    int limit=sqrt(5000);
	int i=0;
	int j;
	while(Prime[i]<=limit){
	    j=i;
		while(Prime[i]*Prime[j]<=5000){
			SemiPrime.push_back(Prime[i]*Prime[j]);
			j++;
		}
		i++;
	}
	sort(SemiPrime.begin(),SemiPrime.end());
}

int main(){
	int T,N;
	int i;
	int count;
	int limit;
	setPrimes();
	//setSemiPrime();
	scanf("%d",&T);
	while(T>0){
		scanf("%d",&N);
		count=0;
		if(N%2==0){
            printf("%d\n",0);
		}
		else{
			i=0;
			while(i<Prime.size() && N>=2*Prime[i]){
                if(FLAG[N-2*Prime[i]]){
                    count++;
                }
                i++;
			}
			printf("%d\n",count);
		}
		T--;
	}
	return 0;
}
