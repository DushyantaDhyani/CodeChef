#define MODULUS 10000009
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
	int T,j,len;
	long value;
	char arr[1000000];
	cin>>T;
	while(T>0){
		cin>>arr;
		j=0;
		len=strlen(arr)-1;
		cout<<"Length is "<<len<<endl;
		value=1;
		while(j<=len){
			//cout<<j<<"   "<<len-j<<endl;
			if(arr[j]!=arr[len]){
				if(arr[j]!='?' || arr[len]!='?'){				
					value=0;
					break;
				}
			}
			else{
				if(arr[j]=='?'){
					value=((value%MODULUS)*26)%MODULUS;
				}
			}
			cout<<value<<endl;
			j++;
			len--;
		}
		T--;
	}
	return 0;
}
