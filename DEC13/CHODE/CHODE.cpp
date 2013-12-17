#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int count;
	char ch;
};
bool myfunc(struct node Node1,struct node Node2){
	if(Node1.count<Node2.count){
		return true;
	}
	else if(Node1.count>Node2.count){
		return false;
	}
	else{
		if(Node1.ch<Node2.ch){
			return true;
		}
		else{
			return false;
		}
	}
}
int main(){
	int T,i,j;
	scanf("%d\n",&T);
	string str1,str2;
	char c;
	while(T>0){
		getline(cin,str1);
		getline(cin,str2);
		vector<struct node> Data;
		for(i=0;i<26;i++){
			struct node Node;
			Node.count=0;
			Node.ch=(char)('a'+i);
			Data.push_back(Node);
		}
		for(i=0;i<str2.length();i++){
			c=str2[i];
			if((c>=65 && c<=90)||(c>=97 && c<=122)){
				if(c>=65 && c<=90){
					c+=32;
				}
				Data[c-'a'].count++;
			}
		}
		sort(Data.begin(),Data.end(),myfunc);
		for(i=0;i<str2.length();i++){
			c=str2[i];
			if((c>=65 && c<=90)||(c>=97 && c<=122)){
				if(c>=65 && c<=90){
					c+=32;
					for(j=0;j<26;j++){
						if(c==Data[j].ch){
							printf("%c",(str1[j]-32));
							break;
						}
					}
				}
				else{
					for(j=0;j<26;j++){
						if(c==Data[j].ch){
							printf("%c",str1[j]);
							break;
						}
					}
				}
			}
			else{
				printf("%c",c);
			}
		}
		printf("\n");
		T--;
	}
	return 0;
}
