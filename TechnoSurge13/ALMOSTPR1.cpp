#define MAX 1000000
#include<iostream>
#include<cmath>
#include<vector>
#include<cstdio>
using namespace std;
bool flag[MAX+1];
vector<int> FLAG;
int setPrimeFlags(){
        	int i,j;
			 i=0;
			 while(i<MAX){
			 	flag[i]=true;
			 	i++;
			 }
			 int limit=sqrt(MAX);
			 i=2;
			 while(i<=limit){
			 	if(flag[i-1]){
			 	    FLAG.push_back(i);
			 		j=i;
			 		while(j*i<MAX){
			 			flag[j*i-1]=false;
			 			j++;
			 		}
			 	}
			 	i++;
			 }
			 while(i<(MAX)){
                if(flag[i-1]){
                    FLAG.push_back(i);
                }
                i++;
             }
			 return FLAG.size();
}
int findFactors(long num,int limit){
	int
	i=0;
	int range=sqrt(num);
	int num1;
	int count=2;
	while(i<limit && FLAG[i]<=range){
		if(num%FLAG[i]==0){
			if(FLAG[i]!=(num/FLAG[i])){
				count+=2;
			}
			else{
				count+=1;
			}
		}
		i++;
	}
	return count;
}
int main(){
	int T;
	scanf("%d",&T);
	long P;
	int psize=setPrimeFlags();
	while(T>0){
		scanf("%ld",&P);
		if(findFactors(P,psize)==3){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		T--;
	}
	return 0;
}