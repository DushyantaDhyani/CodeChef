#include<iostream>
using namespace std;
int main(){
	int T,N,i,ctr;
	cin>>T;
	while(T>0){
		cin>>N;
		int arr[N];
		i=0;
		ctr=1;
		while(i<N){
			cin>>arr[i];
			i++;
		}
		while(i<(N-1)){
			if(arr[i+1]>arr[i]){
				arr[i+1]=arr[i];	
			}
			else{
				ctr++;
			}
			i++;
		}
		cout<<ctr<<endl;
		T--;
	}
	return 0;
}
