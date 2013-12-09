#include<stdio.h>
//#include<conio.h>
void sort(int arr1[],int arr2[],int arr3[],int low,int mid,int high);
void sortByStartTime(int arr1[],int arr2[],int arr3[],int low,int high);
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
	           sortByStartTime(Start,End,Compensation,0,(N-1));
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
void sortByStartTime(int arr1[],int arr2[],int arr3[],int low,int high){
	int mid;
	if((high-low)!=0)
	{
		mid=(low+high)/2;
		sortByStartTime(arr1,arr2,arr3,low,mid);
		sortByStartTime(arr1,arr2,arr3,mid+1,high);
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
		if(arr1[i]<arr1[j])
		{
			temparr2[k]=arr2[i];
			temparr1[k]=arr1[i];
			temparr3[k]=arr3[i];
			i++;
			k++;
		}
		else if(arr1[j]<arr1[i])
		{
			temparr2[k]=arr2[j];
			temparr1[k]=arr1[j];
			temparr3[k]=arr3[j];
			j++;
			k++;
		}
		else if(arr1[i]==arr1[j])
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
