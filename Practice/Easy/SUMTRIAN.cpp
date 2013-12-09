#include<iostream>
using namespace std;
class Helper{
	private:
		int size;
		int **arr;
		int **result;
	public:
		Helper(int N){
			size=N;
			arr=new int*[size];
			result=new int*[size];
			int i=0;
			while(i<size){
				arr[i]=new int[size];
				result[i]=new int[size];
				i++;
			}
		}
		void getValues(){
			int i,j;
			i=0;
			while(i<size){
				j=0;
				while(j<=i){
					cin>>arr[i][j];
					result[size-(i+1)][j]=0;
					j++;
				}
				i++;
			}
		}
		int findMaxSum(){
			int i,j,k;
			i=size-1;
			j=0;
			k=0;
			while(j<size){
				result[k][j]=arr[i][j];
				j++;
			}
			i--;
			k++;
			while(i>=0){
				j=0;
				while(j<=i){
					result[k][j]=arr[i][j]+Max(result[k-1][j],result[k-1][j+1]);
					j++;
				}
				result[k][j]=arr[i][j];
				i--;
				k++;
			}
			return result[size-1][0];
		}
		int Max(int a,int b){
			return (a>b?a:b);
		}
};
int main(){
	int T;
	cin>>T;
	while(T>0){
		int N;
		cin>>N;
		Helper ob(N);
		ob.getValues();
		cout<<ob.findMaxSum()<<endl;
		T--;
	}
	return 0;
}
