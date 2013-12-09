#include<iostream>
using namespace std;
void findPal(int number,int count);
int findNumRev(int number);
int checkPal(int number);
int main(){
	int T;
	int num;
	int count;
	cin>>T;
	while(T>0){
		cin>>num;
		findPal(num,0);
		T--;
	}
	return 0;
}
void findPal(int number,int count){
	if(checkPal(number)){
		cout<<count<<" "<<number<<endl;
	}
	else{
		findPal(number+findNumRev(number),count+1);
	}
}
int findNumRev(int number){
	int temp=number;
	int rev=0;
	while(temp>0){
		rev=(rev*10)+(temp%10);
		temp=temp/10;
	}
	return rev;
}
int checkPal(int number){
	if(number==findNumRev(number)){
		return 1;
	}
	else{
		return 0;
	}
}
