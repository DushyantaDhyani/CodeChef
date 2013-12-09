#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
typedef struct node{
	int x;
	int y;
};
bool myfunc(struct node s1,struct node s2){
	return ((s1.y<s2.y)?true:false);
}
class Helper{
	private:
		int *arr;
		int size;
		int paths;
		int swap;
		map<int,int> Data;
		map<int,int>::iterator it,it1;
	public:
		Helper(int N,int M){
			size=N+1;
			paths=M;
			arr=new int[size];
			int i=0;
			while(i<size){
				arr[i]=i;
				i++;
			}
		}
		void setStructure(){
			int i=1;
			int A,B;
			while(i<=paths){
				scanf("%d %d",&A,&B);
				if(A>B){
					unionData(B,A);
				}
				else{
					unionData(A,B);
				}
				i++;
			}
		}
		void unionData(int x,int y){
			x=find(x);
			y=find(y);
			if(x!=y){
				if(x<y){
					arr[y]=x;
				}
				else{
					arr[x]=y;
				}
			}
		}
		int find(int x){
			while(x!=arr[x]){
				x=arr[x];
			}
			return x;
		}
		void setWeights(){
			int i=1;
			int C;
			int X;
			while(i<=size){
				scanf("%d",&C);
				if(arr[i]==i){
					Data[i]=C;
				}
				else{
					X=find(i);
					it=Data.find(X);
					if((*it).second>=0){
						if(C>=0 && C< ((*it).second)){
							(*it).second=C;
						}
					}
					else{
						if(C>=0){
							(*it).second=C;
						}
					}
				}
				i++;
			}
		}
		long getCost(){
			if(Data.size()==1){
				return 0;
			}
			long Total=0;
			vector<node> arr;
			it=Data.begin();
			while(it!=Data.end()){
				if((*it).second<0){
					return -1;
				}
				node Node;
				Node.x=(*it).first;
				Node.y=(*it).second;
				arr.push_back(Node);
				it++;
			}
			sort(arr.begin(),arr.end(),myfunc);
			int i=0;
			int j=i+1;
			while(j<arr.size()){
				Total+=arr[i].y+arr[j].y;
				j++;
			}
			return Total;
		}
};
int main(){
	int N,M;
	int swap;
	scanf("%d %d",&N,&M);
	if(N==1){
		printf("0\n");
	}
	else{
		Helper ob(N,M);
		ob.setStructure();
		ob.setWeights();
		printf("%ld\n",ob.getCost());
	}
	return 0;
}
