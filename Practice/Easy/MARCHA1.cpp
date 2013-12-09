#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
class Helper{
	private:
		vector <int>arr;
		int size,Amount;
	public:
		Helper(int N,int M){
			size=N;
			Amount=M;
			arr.resize(size);
		}
		void getValues(){
			int i=0;
			while(i<size){
				scanf("%d",&arr[i]);
				i++;
			}
			sort(arr.begin(),arr.end());
		}
		bool findSet(int index,int Total){

		}
};
int main(){
	int T;
	int N,M;
	scanf("%d",&T);
	while(T>0){
		scanf("%d %d",&N,&M);
		Helper ob(N,M);
		ob.getValues();
		if(ob.findSet(0,0)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		T--;
	}
	return 0;
}
