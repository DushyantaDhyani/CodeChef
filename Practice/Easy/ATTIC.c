#define MAX 1000000
#include<stdio.h>
#include<string.h>
int main(){
	int T;
	scanf("%d",&T);
	char str[MAX+1];
	int i,j;
	int count,TempMax,Max;
	int len;
	while(T>0){
		scanf("%s",str);
		len=strlen(str);
		i=0;
		count=0;
		Max=0;
		while(i<len){
			if(str[i]=='#'){
				i++;
			}
			else{
				TempMax=0;
				j=i;
				while(str[j]!='#'){
					TempMax++;
					j++;
				}
				if(TempMax>Max){
					Max=TempMax;
					count++;
				}
				i=j;
			}
		}
		printf("%d\n",count);
		T--;
	}
	return 0;
}
