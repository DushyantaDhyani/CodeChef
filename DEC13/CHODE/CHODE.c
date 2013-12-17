#include<stdio.h>
#include<stdlib.h>
int main(){
	int T;
	char str[27];
	char text[150001];
	scanf("%d",&T);
	int i=1;
	while(T>0){
		fflush(stdin);
		scanf("%s",str);
		fflush(stdin);
		gets(text);
		printf("%s and %s\n",str,text);	
		T--;
	}
	return 0;
}
