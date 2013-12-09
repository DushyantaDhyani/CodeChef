#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(){
	int T,N;
	int i=0;
	int j;
	long num;
	long mindiff;
	cin >> T;
	while(i<T){
			   cin >> N;
			   vector<long> arr(N);
			   j=0;
			   while(j<N){
			   			   cin >> arr[j];
			   			   j++;
			   }
			   sort(arr.begin(),arr.end());
			   j=1;
			   mindiff=arr[1]-arr[0];
			   while(j<(arr.size()-1)){
			   		if((arr[j+1]-arr[j])<mindiff){
 													 mindiff=(arr[j+1]-arr[j]);
					 }
					 j++;
			   }
			   cout<<mindiff<<endl;
    		   i++;
	}
}
