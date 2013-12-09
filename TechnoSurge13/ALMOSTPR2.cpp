#define MAX 1000000
#include<iostream>
//#include<cmath>
#include<math.h>
#include<vector>
#include<cstdio>
#include<algorithm>
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
double squareroot(long num){
	
}
int main(){
	int T;
	int psize=setPrimeFlags();
	printf("SIze is %d\n",psize);
	scanf("%d",&T);
	long P;
	long val;
	int i,j,k;
	while(T>0){
		scanf("%ld",&P);
		val=squareroot(P);
		if((val*val)==P){
			if(binary_search(FLAG.begin(),FLAG.end(),val)){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
		else{
			printf("NO\n");
		}
		T--;
	}
	return 0;
}