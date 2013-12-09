#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
class Helper{
	private:
		char **arr;
		int size;
		int ctr;
		public:
		Helper(int x){
			int i=0;
			size=x;
			arr=new char*[size];
			while(i<size){
				arr[i]=new char[size];
				i++;
			}
			ctr=0;
		}
		void getValues(){
			int i,j;
			i=0;
			while(i<size){
				j=0;
				scanf("%s",arr[i]);
				while(j<size){
					if(arr[i][j]=='B'){
						ctr++;
					}
					j++;
				}
				i++;
			}
		}
		void find(){
			if(ctr>=(size*size/2)){
				printf("%d\n",getResult('W'));
			}
			else{
				printf("%d\n",getResult('B'));
			}
		}
		int getResult(char x){
			char temp;
			if(x=='B'){
				temp='W';
			}
			else{
				temp='B';
			}
			int i,j;
			int count=0;
			int flag=0;
			i=0;
			while(i<size){
				j=0;
				while(j<size){
					if(arr[i][j]==x && !flag){
						count++;
						flag=1;
					}
					if(arr[i][j]!=x && flag){
						flag=0;
					}
					j++;
				}
				i++;
				flag=0; 
			}
			return count;
		}
};
int main(){
	int N;
	scanf("%d",&N);
	Helper ob(N);
	ob.getValues();
	ob.find();
}