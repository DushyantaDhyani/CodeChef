#include<iostream>
using namespace std;
int main(){
	int T,N,M,i,j;
    int temp,flag;
	cin>>T;
	while(T>0){
			   cin>>N>>M;
			   int ChakraSoi[N];
			   int LevelSoi[N];
			   int ChakraSof[M];
			   int LevelSof[M];
			   i=0;
			   while(i<N){
			   			  cin>>ChakraSoi[i]>>LevelSoi[i];
 			   			  i++;
				}
				i=0;
				while(i<M){
						   cin>>ChakraSof[i]>>LevelSof[i];
						   i++;		   
	            }
				for(i=0;i<(N-1);i++){
									for(j=0;j<(N-i-1);j++){
												      if(LevelSoi[j]>LevelSoi[j+1]){
									     					temp=LevelSoi[j];		 
									  						LevelSoi[j]=LevelSoi[j+1];
									  						LevelSoi[j+1]=temp;
												   			temp=ChakraSoi[j];
															ChakraSoi[j]=ChakraSoi[j+1];
															ChakraSoi[j+1]=temp;
												    							  
									      }
								}
				}
				 for(i=0;i<(M-1);i++){
									for(j=0;j<(M-i-1);j++){
				    			      if(LevelSof[j]>LevelSof[j+1]){
									  						temp=LevelSof[j];		 
									  						LevelSof[j]=LevelSof[j+1];
									  						LevelSof[j+1]=temp;
															temp=ChakraSof[j];
															ChakraSof[j]=ChakraSof[j+1];
															ChakraSof[j+1]=temp;
												    							  
									      }
								}
				}
				for(i=0;i<(N-1) ;i++){
								for(j=0;j<(N-i-1);j++){
								      if(LevelSoi[j]==LevelSoi[j+1]){
												   	if(ChakraSoi[j]>ChakraSoi[j+1]){
								                			temp=ChakraSoi[j];
															ChakraSoi[j]=ChakraSoi[j+1];
															ChakraSoi[j+1]=temp;
												    }							  
									      }
								}
				}
	           for(i=0;i<(M-1);i++){
								for(j=0;j<=(M-i-1);j++){
								      if(LevelSof[j]==LevelSof[j+1]){
												   	if(ChakraSof[j]>ChakraSof[j+1]){
								                			temp=ChakraSof[j];
															ChakraSof[j]=ChakraSof[j+1];
															ChakraSof[j+1]=temp;
					
												    }							  
									      }
								}
				}
			
			   T--;		   
    }
    int z;
    cin>>z;
	return 0;
}
