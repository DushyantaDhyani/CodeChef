#include<iostream>
#include<vector>
#include<cmath>
#define MAX 10000000
using namespace std;
bool flag[MAX];
vector<int> arr;
class Helper{
    private:
        int **arr;
        int i,j;
        int size;
    public:
        Helper(int x){
            size=x;
            arr=new int*[size];
            i=0;
            while(i<size){
                arr[i]=new int[size];
                i++;
            }
        }
};
void setFlag(){
    int i,j;
    i=0;
	while(i<=MAX){
        flag[i]=true;
        i++;
	}
	int limit=sqrt(MAX);
	arr.push_back(2);
	i=3;
	while(i<=limit){
		 	if(flag[i/2-1]){
		 	        arr.push_back(i);
			 		j=i;
			 		while(j*i<MAX){
			 			flag[j*i/2-1]=false;
			 			j+=2;
			 		}
		 	}
		 	i+=2;
	 }
}
int main(){
    int T,N;
    cin>>T;
    while(T>0){
        cin>>N;
        Helper ob(N);
        ob.getValues();
        ob.findTries();
        T--;
    }
	return 0;
}
