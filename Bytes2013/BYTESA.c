#include<stdio.h>
#include<string.h>
int main(){
	char str[52];
	int T;
	int i;
	scanf("%d",&T);
	int len;
	char ch;
	while(T>0){
		scanf("%s",str);
		len=strlen(str);
		i=0;
		while(i<len){
			ch=str[i];
			if(ch=='2' || ch=='3' || ch=='5' || ch=='4' || ch=='7'){
				printf("NO\n");
				break;
			}
			i++;
		}
		if(i>=len){
			printf("YES\n");
		}
		T--;
	}
	return 0;
}