#include<iostream>
#include<cstdlib>
#include<sstream>
#include<vector>
using namespace std;
int main(){
	int T,N;
	int num;
	cin>>T;
	int i=1;
	int max,pos;
	while(T>0){
		cin>>N;
		vector< int > arr(10000);
		i=1;
		while(i<=N){
			cin>>num;
			arr[num-1]++;
			i++;
		}
		max=arr[0];
		pos=0;
		i=1;
		while(i<=9999){
			if(arr[i]>max){
				max=arr[i];
				pos=i;
			}
			i++;
		}
		cout<<pos+1<<" "<<max<<endl<<flush;
		T--;
	}
	return 0;
}
