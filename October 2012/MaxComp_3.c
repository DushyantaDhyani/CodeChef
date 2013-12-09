#include<stdio.h>
//#include<conio.h>
void sortByStartTime(int arr1[],int arr2[],int arr3[],int high);
int main(){
	int T;
	int N,i,j,k;
	scanf("%d",&T);	
	while(T>0){
			   scanf("%d",&N);
			   int Start[N];
			   int End[N];
			   int Compensation[N];
			   int NextIndex[N-1];
			   long Value[N];
			   i=0;
			   while(i<N){
			   			  scanf("%d %d %d",&Start[i],&End[i],&Compensation[i]);
 			   			  i++;
	           }
	           sortByStartTime(Start,End,Compensation,(N-1));
	           i=0;
			   while(i<(N-1)){
			   			  j=i+1;
			   			  while(j<N){
						  			 if(Start[j]>=End[i]){
									 					  break;					  
				                     }
  			              			 j++;
						  }
						  if(j<N)
						  NextIndex[i]=j;
						  else
						  NextIndex[i]=-1;
 			   			  i++;
				}		
				Value[N-1]=Compensation[N-1];		
				i=N-2;							
				while(i>=0){
							if(NextIndex[i]!=-1)
							Value[i]=max(Compensation[i]+Value[NextIndex[i]],Value[i+1]);
							else
							Value[i]=max(Compensation[i],Value[i+1]);
							i--;
				}	   
				printf("%ld\n",Value[0]);
			   T--;		   
    }
  //getch();
    return 0;
}
int max(int x,int y){
	if(x>y){
			return x;
	}
	return y;
}
void sortByStartTime(int arr1[],int arr2[],int arr3[],int high){
	 int i,j,flag;
	 flag=1;
	 int temp;
	 for(i=0;i<=(high-1) && flag;i++){
	 			flag=0;
	            for(j=0;j<=(high-i-1);j++){
   						   if(arr1[j]>arr1[j+1]){
            					 temp=arr1[j];
            					 arr1[j]=arr1[j+1];
            					 arr1[j+1]=temp;
            					 temp=arr2[j];
            					 arr2[j]=arr2[j+1];
            					 arr2[j+1]=temp;
            					 temp=arr3[j];
            					 arr3[j]=arr3[j+1];
            					 arr3[j+1]=temp;
            					 flag=1;
							}
				}
	 }
}
