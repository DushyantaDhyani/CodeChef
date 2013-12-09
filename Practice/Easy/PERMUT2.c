#include<stdio.h>
int main(){
    int N;
    while(1){
	    scanf("%d",&N);
	    if(N==0){
		    break;
	    }
	    register int i;
	    int inp[N];
	    int out[N];
	    i=0;
	    while(i<N){
		    scanf("%d",&inp[i]);
		    i++;
	    }
	    i=0;
	    while(i<N){
		    out[inp[i]-1]=i+1;
		    i++;
	    }
	    i=0;
	    while(i<N){
		    if(inp[i]!=out[i]){
			    break;
		    }
		    i++;
	    }
	    if(i<N){
		    printf("not ambiguous\n");
	    }
	    else{
		    printf("ambiguous\n");
	    }
    }
    return 0;
} 
