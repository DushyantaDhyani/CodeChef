#define MAX 10000000/2
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int
class Helper{
	private:
		int size;
		int **arr;
		bool flag[MAX+1];
		int i,j;
		int tries;
	public:
		Helper(int x){
			size=x;
			tries=0;
			arr=new int*[size];
			i=0;
			while(i<size){
				arr[i]=new int[size];
				i++;
			}
		}
		void getValues(){
			i=0;
			j=0;
			while(i<size){
				j=0;
				while(j<size){
					cin>>arr[i][j];
					j++;
				}
				i++;
			}
		}
		int findValue(int x,int y){
			int temp;
			if(arr[x][y]%2==0 && arr[x][y]!=2){
				temp=arr[x][y]/2;
				setEven(x,y);
				cout<<"Returned "<<temp<<"from as even"<<x<<"  "<<y<<endl;
				return temp;
			}
			else if(!flag[arr[x][y]/2-1]){
				temp=countPrime(arr[x][y]);
				cout<<"Returned "<<temp<<"from as prime"<<x<<"  "<<y<<endl;
				return temp;
			}
			else{
				temp=(arr[x][y]+1)/2+1;
				setOdd(x,y);
				cout<<"Returned "<<temp<<"from as odd"<<x<<"  "<<y<<endl;
				return temp;
			}
		}
		void setEven(int x,int y){
			if(x<0 || x>size || y<0 || y>size){
				return;
			}
			arr[x][y]=-1;
			if(arr[x][y]%2==0){
			      setEven(x-1,y);
			      setEven(x,y+1);
			      setEven(x+1,y);
			      setEven(x,y-1);
			}
		}
		void setOdd(int x,int y){
			if(x<0 || x>size || y<0 || y>size){
				return;
			}
			if(arr[x][y]%2!=0){
			      arr[x][y]=-1;
			      setOdd(x-1,y);
			      setOdd(x,y+1);
			      setOdd(x+1,y);
			      setOdd(x,y-1);
			}
		}
		int countPrime(int x){
			int count=0;
			int j=0;
			while(j<x){
				if(flag[j]==1){
					count++;
				}
				j++;
			}
			return count;
		}
		void setFlags(){
			int i,j;
		        for(i=1;i<=MAX;i++){
		        	 flag[i] = 1;
		        }
		        for(i=2;i<=(int)sqrt(MAX);i++) {
			        if (flag[i]) {
			                for(j=i;j*i<MAX;j++){
			                	 flag[i*j] = 0;
			                }
			        }
			}
		}
		void setPrimeFlags(){
			 int i,j;
			 i=3;
			 while(i<=MAX){
			 	flag[i]=true;
			 	i++;
			 }
			 int limit=sqrt(MAX);
			 while(i<=limit){
			 	if(!arr[i]){
			 		j=i;
			 		while(j*i<MAX){
			 			arr[j*i]=false;
			 			j+=2;
			 		}
			 	}
			 	i+=2;
			 }
		}
		void findTries(){
			i=0;
			while(i<size){
				j=0;
				while(j<size){
					if(arr[i][j]!=-1){
						tries+=findValue(i,j);
					}
					j++;
				}
				i++;
			}
			cout<<tries<<endl;
		}
};
int main(){
	int T;
	cin>>T;
	int N;
	setFlags();
	while(T>0){
		cin>>N;
		Helper ob(N);
		ob.getValues();
		ob.findTries();
		T--;
	}
	return 0;
}
