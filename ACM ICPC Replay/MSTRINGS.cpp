#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
bool checkString(string st,string reverse){
	int len=st.length();
	int i,j;
	i=0;
	string temp;
	while(i<len){
		j=i+1;
		while(j<=len){
			temp=st.substr(i,j);
			if(reverse.find(temp)==string::npos){
				return false;
			}
			j++;
		}
		i++;
	}
	return true;
}
string getReverse(string st){
	int len=st.length();
	string temp="";
	int i=len-1;
	while(i>=0){
		temp+=st[i];
		i--;
	}
	return temp;
}
int main(){
	int T;
	string str;
	scanf("%d",&T);
	while(T>0){
		cin>>str;
		string reverse=getReverse(str);
		if(checkString(str,reverse)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		T--;
	}
	return 0;
}