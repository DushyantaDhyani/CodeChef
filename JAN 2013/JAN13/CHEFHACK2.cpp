#define MAX 10000000
#include<iostream>
#include<cmath>
#include<vector>
#include<cstdio>
using namespace std;
bool flag[MAX];
vector<int> FLAG;
int setPrimeFlags(){
        	int i,j;
			 i=0;
			 while(i<MAX){
			 	flag[i]=true;
			 	i++;
			 }
			 int limit=sqrt(MAX);
			 i=2;
			 while(i<=limit){
			 	if(flag[i-1]){
			 	    FLAG.push_back(i);
			 		j=i;
			 		while(j*i<MAX){
			 			flag[j*i-1]=false;
			 			j++;
			 		}
			 	}
			 	i++;
			 }
			 while(i<(MAX)){
                if(flag[i-1]){
                    FLAG.push_back(i);
                }
                i++;
             }
			 return FLAG.size();
}
class Helper{
	private:
		int size;
		int psize;
		int **arr;
		int i,j;
		long long tries;
	public:
		Helper(int x,int y){
		    psize=y;
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
		int findPrimeVal(int x,int y){
			int p=0;
			int q=psize-1;
			int k;
			while(p<=q){
			    k=(p+q)/2;
                if(FLAG[k]==arr[x][y]){
                    return (k);
                }
                else if(FLAG[k]>arr[x][y]){
                    q=k-1;
                }
                else{
                    p=k+1;
                }
			}
			return -1;
		}
		int findValue(int x,int y){
		    int temp;
			if(arr[x][y]%2==0 && arr[x][y]!=2){
				temp=arr[x][y]/2;
				setEven(x,y);
				//cout<<" Returning For Even "<<arr[x][y]<<" "<<temp<<endl;
				return temp;
			}
			else if((temp=findPrimeVal(x,y))!=-1){
			    arr[x][y]=-1;
			    return (temp);
            }
			else{
				temp=(arr[x][y]+1)/2+1;
				setOdd(x,y);
				return temp;
			}
		}
		void setEven(int x,int y){
			if(x<0 || x>=size || y<0 || y>=size){
				return;
			}
			if(arr[x][y]!=-1 && arr[x][y]%2==0 && arr[x][y]!=2){
			      arr[x][y]=-1;
			      setEven(x-1,y);
			      setEven(x,y+1);
			      setEven(x+1,y);
			      setEven(x,y-1);
			}
		}
		void setOdd(int x,int y){
			if(x<0 || x>=size || y<0 || y>=size){
				return;
			}
			if(arr[x][y]!=-1 && arr[x][y]%2!=0 && (findPrimeVal(x,y))==-1){
			      arr[x][y]=-1;
			      setOdd(x-1,y);
			      setOdd(x,y+1);
			      setOdd(x+1,y);
			      setOdd(x,y-1);
			}
		}
		void findTries(){
			i=0;
			tries=0;
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
	int psize=setPrimeFlags();
	while(T>0){
		cin>>N;
		Helper ob(N,psize);
		ob.getValues();
		ob.findTries();
		T--;
	}
	return 0;
}
