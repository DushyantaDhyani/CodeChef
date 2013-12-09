#include<stdio.h>
#include<string.h>
int main(){
	int T;
	scanf("%d",&T);
	char str[315];
	int len;
	int i;
	while(T>0){
		scanf("%s",str);
		int arr[26];
		len=strlen(str);
		i=0;
		memset(str,0,sizeof(arr));
		while(i<len){
			if(str[i]>=65 && str[i]<=90){
				arr[str[i]-65]++;
			}
			else if(str[i]>=97 && str[i]<=122){
				arr[str[i]-97]++;
			}
			i++;
		}
		i=0;
		while(i<26){
			if(arr[i]==0){
				printf("%c\n",(i+65));
				break;
			}
			i++;
		}
		T--;
	}
}