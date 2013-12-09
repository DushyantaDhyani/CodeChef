#include<stdio.h>
//#include<conio.h>
void sort(int arr1[],int arr2[],int arr3[],int low,int mid,int high);
void sortByEndTime(int arr1[],int arr2[],int arr3[],int low,int high);
int main(){
	int T;
	int N,i,j,k;
	scanf("%d",&T);	
    long MaxValue,Value;
	while(T>0){
			   scanf("%d",&N);
			   MaxValue=Value=0;
			   int Start[N];
			   int End[N];
			   int Compensation[N];
			   i=0;
			   while(i<N){
			   			  scanf("%d %d %d",&Start[i],&End[i],&Compensation[i]);
 			   			  i++;
	           }
	           sortByEndTime(Start,End,Compensation,0,(N-1));
	           i=0;
	           while(i<N){
			   		Value=Compensation[i];
					j=i;
					while(j<N){
							   k=End[j];
							   while(j<N && Start[j]<k ){
	   					       					 j++;
			                   }
							   if(j<N){
							   		   Value+=Compensation[j];		   
                               }
     				}   	  
     				if(Value>MaxValue){
		          					   MaxValue=Value;
				    }
			   		i++;
				}
				printf("%ld\n",MaxValue);
			   T--;		   
    }
  //getch();
    return 0;
}
void sortByEndTime(int arr1[],int arr2[],int arr3[],int low,int high){
	int mid;
	if((high-low)!=0)
	{
		mid=(low+high)/2;
		sortByEndTime(arr1,arr2,arr3,low,mid);
		sortByEndTime(arr1,arr2,arr3,mid+1,high);
		sort(arr1,arr2,arr3,low,mid,high);
			
	}
}
void sort(int arr1[],int arr2[],int arr3[],int low,int mid,int high){
	int temparr1[high-low+1];
	int temparr2[high-low+1];
	int temparr3[high-low+1];
	int i,j,k;
	i=low;
	j=mid+1;
	k=0;
	while(i<=mid && j<=high)
	{
		if(arr2[i]<arr2[j])
		{
			temparr2[k]=arr2[i];
			temparr1[k]=arr1[i];
			temparr3[k]=arr3[i];
			i++;
			k++;
		}
		else if(arr2[j]<arr2[i])
		{
			temparr2[k]=arr2[j];
			temparr1[k]=arr1[j];
			temparr3[k]=arr3[j];
			j++;
			k++;
		}
		else if(arr2[i]==arr2[j])
		{
			temparr2[k]=arr2[i];
			temparr1[k]=arr1[i];
			temparr3[k]=arr3[i];
			k++;
			i++;
			temparr2[k]=arr2[j];
			temparr1[k]=arr1[j];
			temparr3[k]=arr3[j];
			j++;
			k++;
			
		}
	}
	while(i<=mid)
	{
		temparr2[k]=arr2[i];
			temparr1[k]=arr1[i];
			temparr3[k]=arr3[i];
			k++;
		i++;
	}
	while(j<=high)
	{
		temparr2[k]=arr2[j];
			temparr1[k]=arr1[j];
			temparr3[k]=arr3[j];
			j++;
		k++;
	}
	i=low;
	j=0;
	while(i<=high)
	{
		arr1[i]=temparr1[j];
		arr2[i]=temparr2[j];
		arr3[i]=temparr3[j];
		i++;
		j++;	
	}
}
