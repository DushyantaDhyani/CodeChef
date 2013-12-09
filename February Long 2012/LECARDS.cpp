#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
class Helper{
	private:
		vector<int> arr;
		int i;
		int num;
	public:
		Helper(int x){
			i=1;
			while(i<=x){
				scanf("%d",&num);
				arr.push_back(num);
				i++;
			}
		}
		void powerSet()
}
int main(){
	int T,N;
	scanf("%d",&T);
	while(T>0){
		scanf("%d",&N);
		Helper ob(N);
		ob.getValues();
		ob.powerSet();
		T--;
	}
	return 0;
}