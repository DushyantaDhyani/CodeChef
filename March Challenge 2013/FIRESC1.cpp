#define MOD 1000000007
#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
using namespace std;
typedef struct Node{
	bool FLAG;
	vector<int> Nodes;
};
class Helper{
	private:
		vector<Node> Data;
		vector<int> Nodes;
		int queries;
		int size;
		long Total;
		int NOP;
		int temp;
	public:
		Helper(int N,int M){
			NOP=0;
			Total=1;
			size=N;
			queries=M;
			Data.resize(1+size);
			register int i=0;
			while(i<=size){
				Node node;
				node.FLAG=0;
				Data.push_back(node);
				i++;
			}
		}
		void getQuery(){
			register int i=1;
			register int x,y;
			while(i<=queries){
				scanf("%d %d",&x,&y);
				Data[x].Nodes.push_back(y);
				Data[y].Nodes.push_back(x);
				i++;
			}
		}
		void getComponents(){
			int i=1;
			while(i<=size){
				if(!(Data[i].FLAG)){
					temp=0;
					++NOP;
					setComponents(i);
					Total=(Total*(temp)%MOD)%MOD;
				}
				i++;
			}
		}
		void setComponents(int x){
			if(!Data[x].FLAG){
				temp++;
				vector<int>::iterator it;
				Data[x].FLAG=1;
				it=Data[x].Nodes.begin();
				while(it!=(Data[x].Nodes.end())){
					setComponents(*it);
					it++;
				}
			}
		}
		int getPaths(){
			return NOP;
		}
		long getTotal(){
			return Total;
		}
};
int main(){
	int T;
	int N,M;
	scanf("%d",&T);
	while(T>0){
		scanf("%d %d",&N,&M);
		Helper ob(N,M);
		ob.getQuery();
		ob.getComponents();
		cout<<ob.getPaths()<<" "<<ob.getTotal()<<endl;
		T--;
	}
	return 0;
}