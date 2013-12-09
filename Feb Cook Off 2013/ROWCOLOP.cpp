#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int N,Q;
	scanf("%d %d",&N,&Q);
	vector<int> arr1(N);
	vector<int> arr2(N);
	int i=1;
	char str[20];
	int X,Y;
	while(i<=Q){
		scanf("%s %d %d",str,&X,&Y);
		if(str[0]=='R'){
			arr1[X-1]+=Y;
		}
		else{
			arr2[X-1]+=Y;
		}
		i++;
	}
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
	printf("%d",(arr1[N-1]+arr2[N-1]));
	return 0;
}