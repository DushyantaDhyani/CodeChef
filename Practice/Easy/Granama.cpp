#include<iostream>
#include<string>
using namespace std;
class Helper{
	private:
		string recipe1,recipe2;
		int arr1[26],arr2[26];
		int i,j;
		int len1,len2;
	public:
		Helper(string s1,string s2){
			recipe1=s1;
			recipe2=s2;
			len1=recipe1.length();
			len2=recipe2.length();
			i=0;
			while(i<26){
				arr1[i]=0;
				arr2[i]=0;
				i++;
			}
		}
		void find(){
			i=0;
			while(i<len1){
				arr1[recipe1[i]-97]++;
				i++;
			}
			i=0;
			while(i<len2){
				if(arr1[recipe2[i]-97]==0){
					break;
				}
				arr2[recipe2[i]-97]++;
				i++;
			}
			if(i<len2){
				cout<<"YES"<<endl;
			}
			else{
				i=0;
				while(i<26){
					if(arr1[i]!=arr2[i]){
						cout<<"NO"<<endl;
						break;
					}
					i++;
				}
				if(i>=26){
					cout<<"YES"<<endl;
				}
			}
		}
};
int main(){
	int T;
	string str1,str2;
	cin>>T;
	while(T>0){
		cin>>str1>>str2;
		Helper ob(str1,str2);
		ob.find();
		T--;
	}
	return 0;
}
