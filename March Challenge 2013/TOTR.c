#include<stdio.h>
#include<string.h>
int main(){
	int T;
	char str[27];
	char convo[101];
	int len,i;
	scanf("%d %s",&T,str);
	while(T>0){
		scanf("%s",convo);
		len=strlen(convo);
		i=0;
		while(i<len){
			if(convo[i]>=97 && convo[i]<=122){
				printf("%c",str[convo[i]-97]);
			}
			else if(convo[i]>=65 && convo[i]<=90){
				printf("%c",(str[convo[i]-65]-32));
			}
			else if(convo[i]=='_'){
				printf(" ");
			}
			else{
				printf("%c",convo[i]);
			}
			i++;
		}
		printf("\n");
		T--;
	}
	return 0;
}