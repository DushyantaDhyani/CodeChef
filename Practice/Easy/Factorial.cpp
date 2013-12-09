//Easy
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int T,i;
	long num;
	long sum,div;
	cin>>T;
	while(T>0){
		cin>>num;
		i=1;
		sum=0;
		div=(long)pow((double)5,(double)i);
		while(div<=num){
			sum+=num/div;
			i++;
			div=(long)pow((double)5,(double)i);
		}
		cout<<sum<<endl;
		T--;
	}
	return 0;
}
