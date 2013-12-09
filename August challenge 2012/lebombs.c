#include<stdio.h>
#include<stdlib.h>
int main(){
	int T;
	scanf("%d",&T);
	int i=1,N,j,ctr;
	fflush(stdin);
	while(i<=T){
				ctr=0;
				fflush(stdin);
				scanf("%d",&N);
				char str[N];
				int arr[N];
				memset(arr,0,sizeof(arr));
				fflush(stdin);
				gets(str);
				j=0;
				if(N>1){
				while(j<N){
						   if(str[j]=='1'){
  				   		   				   if(j==0){
										   			arr[0]=1;
		   								   			arr[1]=1;
							  			   }
							  			   else if(j==(N-1)){
 					   					   		    arr[j]=1;
 					   					   		    arr[j-1]=1;
						   				   }
						   				   else{
			   							   		arr[j-1]=1;
			   							   		arr[j]=1;
			   							   		arr[j+1]=1;
							  			   }
						   }
						   else{
						   		if(arr[j]!=1)
						   		arr[j]=0;		
						   }
	   					   j++;
	   			}
	   			j=0;
	   			while(j<N){
						   
					if(arr[j]==0)	 
					ctr++;
					j++;
			    }
			    printf("%d\n",ctr);
				}
				else{
			 		 if(str[0]=='1')
			 		 printf("0\n");
			 		 else
			 		 printf("1\n");
				 }
			    i++;
	}
//	getch();
	return 0;
}
