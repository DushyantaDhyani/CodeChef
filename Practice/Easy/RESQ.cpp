#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int T,num,limit,j;
	cin>>T;
	while(T>0){
		cin>>num;
		limit=(int)sqrt(num);
		while(limit>0){
			if(num%limit==0){
				cout<<((num/limit)-limit)<<endl;
				break;
			}
			limit--;
		}
		T--;
	}
	return 0;
}
