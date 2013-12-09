#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
typedef struct Node{
	int sx,sy,ex,ey;
	char val;
};
class Helper{
	private:
		char **arr;
		int size;
		int ctr;
		vector<Node> resultset;
		vector<Node>::iterator it;
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
				scanf("%s",arr[i]);
				i++;
			}
		}
		void find(){
			printf("%d\n",getResult('B'));
			it=resultset.begin();
			while(it!=resultset.end()){
				printf("%d %d %d %d %c\n",(*it).sx,(*it).sy,(*it).ex,(*it).ey,(*it).val);
				it++;
			}
		}
		int getResult(char x){
			Node NewNode;
			int i,j;
			int count=0;
			int flag=0;
			i=0;
			while(i<size){
				j=0;
				while(j<size){
					if(arr[i][j]==x && !flag){
						NewNode.sx=i;
						NewNode.ex=i;
						NewNode.sy=j;
						count++;
						flag=1;
					}
					if(arr[i][j]!=x && flag){
						NewNode.ey=j-1;
						NewNode.val=x;
						resultset.push_back(NewNode);
						flag=0;
					}
					j++;
				}
				if(arr[i][j-1]==x && flag){
						NewNode.ey=j-1;
						NewNode.val=x;
						resultset.push_back(NewNode);
						flag=0;
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