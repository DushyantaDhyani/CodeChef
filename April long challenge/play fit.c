#include<stdio.h>
void enter(long int arr[],long int N);
long int merge_sort(long int arr[],long int low,long int high);
long int sort(long int arr[],long int l,long int m,long int h);

int main()
{
	int t,i,s;
	scanf("%d",&t);
	long int difference;
	long int output[t];
	i=1;
	s=0;
	while(i<=t)
	{
               difference=0;
               long int N;
               scanf("%ld",&N);
	           long int arr[N];
               enter(arr,N);
               difference=merge_sort(arr,0,(N-1));
               output[s]=difference;
               s++;
	           i++;
  }
  i=0;
  while(i<t)
  {
            if(output[i]==0)
            printf("UNFIT\n");
            else
            printf("%ld\n",output[i]);
            i++;
  }
	           return 0;
}
void enter(long int arr[],long int N)
{
	long int i;
	for(i=0;i<N;i++)
	{
		scanf("%ld",&arr[i]);	
	}
}
long int merge_sort(long int arr[],long int low,long int high)
{
	
	if((high-low)==0)
	return 0;
	else
	{
        long int mid,diff1,diff2,diff3,max;
		mid=(low+high)/2;
		diff1=merge_sort(arr,low,mid);
		diff2=merge_sort(arr,mid+1,high);
		diff3=sort(arr,low,mid,high);
		     if(diff1>=diff2)
            {
             if(diff1>=diff3)
             return diff1;
             else 
             return diff3;
            }
            else
            {
             if(diff2>=diff3)
             return diff2;
             else 
             return diff3;
            }
	}
}
long int sort(long int arr[],long int low,long int mid,long int high)
{
	long int temparr[high-low+1];
	long int maxdiff=0;
	long int i,j,k;
	i=low;
	j=mid+1;
	k=0;
	if(arr[low]<arr[high])
	maxdiff=arr[high]-arr[low];
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
            temparr[k]=arr[i];
			i++;
			k++;
		}
		else if(arr[j]<arr[i])
		{
			temparr[k]=arr[j];
			j++;
			k++;
		}
		else if(arr[i]==arr[j])
		{
			temparr[k]=arr[i];
			k++;
			i++;
			temparr[k]=arr[j];
			j++;
			k++;
			
		}
	}
	while(i<=mid)
	{
		temparr[k]=arr[i];
		k++;
		i++;
	}
	while(j<=high)
	{
		temparr[k]=arr[j];
		j++;
		k++;
	}
	i=low;
	j=0;
	while(i<=high)
	{
		arr[i]=temparr[j];
		i++;
		j++;	
	}
	return maxdiff;
}
