#include<stdio.h>
#include<string.h>
int main(){
	int T;
	char str[101];
	int len;
	int i;
	int ctr;
	char ch;
	scanf("%d",&T);
	while(T>0){
		scanf("%s",str);
		len=strlen(str);
		i=0;
		ctr=0;
		while(i<len){
			ch=str[i];
			if(ch=='A' || ch=='D' || ( ch>='O' && ch<='R') ){
				ctr+=1;
			}
			else if(ch=='B'){
				ctr+=2;
			}
			i++;
		}
		printf("%d\n",ctr);
		T--;
	}
	return 0;
}