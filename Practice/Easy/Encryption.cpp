#include<iostream>
#include<string>
using namespace std;
int main(){
	int T,i,factor1,factor2,flag,j;
	string str;
	cin>>T;
	while(T!=0){
		factor1=2*T-1;
		factor2=1;
		flag=0;
		cin>>str;
		i=0;
		while(i<T){
			j=i;
			flag=0;
			while(j<str.length()){
				cout<<str[j];
				if(!flag){
					flag=1;
					j+=factor1;
				}
				else{
					flag=0;
					j+=factor2;
				}
			}
			i++;
			factor1-=2;
			factor2+=2;
		}
		cout<<endl;
		cin>>T;
	}
	
	return 0;
}
