#define MAX 9999999
#include<stdio.h>
int compare(int arr[],long val);
int main(){
	int arr[10]={1,1,2,6,24,120,720,5040,40320,362880};
	long i=10;
	while(i<=MAX){
				  if(compare(arr,i)){
 				  					 printf("%ld",i);
 				  					 //getch();
				   }
    			  i++;
	}
	printf("%ld",i);
	return 0;
}
int compare(int arr[],long val){
	long sum=0;
	long temp=val;
	while(temp>0){
    			  sum+=arr[temp%10];
    			  temp=temp/10;
	}
	if(sum==val){
    			 return 1;
	}
	return 0;
}
