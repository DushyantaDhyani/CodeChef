#include<iostream>
#include<string>
#include<map>
using namespace std;
typedef struct node{
	string country;
	int count;
};
class Helper{
	private:
		int size;
		int query;
		map<string,node> Data1;
		map<string,node>::iterator it1;
		map<string,int> Data2;
		map<string,int>::iterator it2;
	public:
		Helper(int x,int y){
			size=x;
			query=y;
		}
		void getDetails(){
			string temp1,temp2;
			int i;
			i=0;
			while(i<size){
				cin>>temp1>>temp2;
				node temp;
				temp.country=temp2;
				temp.count=0;
				Data1.insert(pair<string,node>(temp1,temp));
				if((it2=Data2.find(temp2))==Data2.end()){
					Data2.insert(pair<string,int>(temp2,1));
				}
				else{
					((*it2).second)++;
				}
				i++;
			}
		}
		void setDetails(){
			int i=0;
			string str;
			while(i<query){
				cin>>str;
				it1=Data1.find(str);
				((*it1).second.count)++;
				it2=Data2.find((*it1).second.country);
				((*it2).second)++;
				i++;
			}
		}
		void findCountry(){
			it2=Data2.begin();
			string str1;
			int count=-1;
			while(it2!=Data2.end()){
				if((*it2).second>count){
					str1=(*it2).first;
					count=(*it2).second;
				}
				else if((*it2).second==count){
					if(((*it2).first).compare(str1)<0){
						str1=(*it2).first;
					}
				}
				it2++;
			}
			cout<<str1<<endl;
		}
		void findName(){
			it1=Data1.begin();
			string str1;
			int countval=-1;
			while(it1!=Data1.end()){
				if(((*it1).second).count>countval){
					str1=((*it1).first);
					countval=((*it1).second).count;
				}
				else if(((*it1).second).count==countval){
					if(((*it1).first).compare(str1)<0){
						str1=(*it1).first;
					}
				}
				it1++;
			}
			cout<<str1<<endl;
		}
};
int main(){
	int N,M;
	cin>>N>>M;
	Helper ob(N,M);
	ob.getDetails();
	ob.setDetails();
	ob.findCountry();
	ob.findName();
	return 0;
}
