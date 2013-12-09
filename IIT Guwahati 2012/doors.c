//#define size 100000000
#include<stdio.h>
#include<stdlib.h>
int main(){
	int size=1000;
	int arr[size];
	int j=1;
	int k;
	long i;
	long limit;
	int ctr;
	memset(arr,0,sizeof(arr));
	arr[0]=1;
	while((j)<size){
				  if(arr[j]!=1){
				  				arr[j]=2;
  				  				i=(j+1)*(j+1)-1;
								while(i<size){
						        		arr[i]=1;
										i=(j+1)+(i);
								}
	              }
    			  j++;
	}
	for(i=1;i<=size;i++){
    				  j=2;
    				  ctr=0;
    				  if(arr[i]!=2){
    			    				  limit=i+1;
	                  				while(j<=limit){
	                                				if(((i+1)%j)==0){
									           	    			 ctr++;
									            				 limit=limit/j;    			 
													}
													else{
												    	 if(ctr>0){
												    	 		   arr[i]=(ctr+1)*arr[limit-1];
												    	 		   ctr=0;
												    	 		   break;
										                 }
										                 else{
									 	                  j++;
														   }
													}
									}
									if(ctr!=0){
						            		   arr[i]=ctr+1;
									}
									
					  }
	}
	int T;
	long val;
	long ctrmain;
	scanf("%d",&T);	
	int m=1;
	while(m<=T){
				scanf("%d",&val);			
				i=0;
				ctrmain=0;
				while(i<val){
			    			 if(arr[i]%2!=0){
			                 			ctrmain++;	 
							 }
							 i++;
				}
				printf("%d\n",ctrmain);
				m++;
	}
	getch();
}
