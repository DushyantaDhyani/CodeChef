#include<stdio.h>
#include<string.h>
char str[1001];
int maxs,maxe;
int magcomp(int x,int y){
	while(str[x]=='0'){
		x++;
	}
	while(str[maxs]=='0'){
		maxs++;
	}
	if((y-x)==(maxe-maxs)){
		while(maxs<=maxe && x<=y){
			if(str[x]>str[maxs]){
				return 1;
			}
			maxs++;
			x++;		
		}
	}
	else if((y-x)>(maxe-maxs)){
		return 1;
	}
	else{
		return 0;
	}
	return 0;	
}
int main(){
	int i,len;
	int prev,current,next;
	scanf("%s",str);
	len=strlen(str);
	int flag;
	i=0;
	while(i<len && str[i]=='0'){
		i++;
	}
	if(i==len){
		maxs=maxe=0;
	}
	else{
		prev=i;
		if(str[prev]>='A' && str[prev]<='Z'){
			str[prev]='9';
			i++;
		}
		while(i<len && str[i]>='0' && str[i]<='9'){
			i++;
		}
		current=i;
		maxs=prev;
		maxe=current-1;
		if(current<len){
			str[current]='9';
			i++;
			while(i<len && str[i]>='0' && str[i]<='9'){
				i++;
			}
			if(i<len){
				next=i;
				while(1){
					str[current]='9';
					flag=magcomp(prev+1,next-1);
					if(flag){
						maxs=prev+1;
						maxe=next-1;
					}
					prev=current;
					current=next;
					i=next+1;
					while(i< len && str[i]>='0' && str[i]<='9'){
						i++;
					}
					if(i==len){
						break;
					}
					next=i;
				}		
			}
			else{
				next=i;
				flag=magcomp(prev+1,next-1);
				if(flag){
					maxs=prev+1;
					maxe=next-1;
				}
			}
		}
	}
	if(maxs==maxe){
		printf("%c",str[maxs]);
	}
	else{
		flag=0;		
		while(maxs<=maxe){
			if(!flag && str[maxs]=='0'){
			}
			else{
				flag=1;
				printf("%c",str[maxs]);
			}
			maxs++;
		}
	}		
	printf("\n");
	return 0;
}
