#include<stdio.h>
void enter(long int arr[],int N);
void merge_sort(long int arr[],int low,int high);
void sort(long int arr[],int l,int m,int h);
int compute(long int arr[],int len);
int find_equal(long int arr[],int len);
int main()
{
	int T;
	scanf("%d",&T);
	int output[T];
	int i=0;
    int N;
    while(i<T)
    {
	 scanf("%d",&N);
	 long int arr[N];
	 enter(arr,N);
	 merge_sort(arr,0,(N-1));
	 output[i]=compute(arr,N);
	 i++;
    }
    i=0;
    while(i<T)
    {
              printf("%d\n",output[i]);
              i++;
    }
	return 0;
}
void enter(long int arr[],int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%ld",&arr[i]);	
	}
}
void merge_sort(long int arr[],int low,int high)
{
	int mid;
	if((high-low)!=0)
	{
		mid=(low+high)/2;
		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);
		sort(arr,low,mid,high);
			
	}
}
void sort(long int arr[],int low,int mid,int high)
{
	long int temparr[high-low+1];
	int i,j,k;
	i=low;
	j=mid+1;
	k=0;
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
}
int compute(long int arr[],int len)
{
    int x;
    int k;
    int ctr=0;
    int j=len;
    int right,left;
    right=0;
    left=len;
    int num=0;
    if(!find_equal(arr,len))
    return 0;
    while(1)
    {
                     while(j>0)
                     {
                               if(arr[j-1]!=arr[len-1])
                               break;
                               j--;
                     }
                     j++;
    
                     right=len-j;
                     left=j-1;
                     if(right>=left)
                     break;
                     else
                     {
                      if(right!=0)
                      {
                       if(right%2==0)
                       num=2*right+1;
                       else
                       num=2*(right+1);
                      }
                      else
                      num=2;
                      if(num>=len)
                      break;
                       k=len;    
                       while(num>0)
                      {
                                  arr[k-1]=arr[len-1];
                                  k--;
                                  num--;
                      }                  
                     }
                     ctr++;
      }
    ctr++;
    return ctr;
}
int find_equal(long int arr[],int len)
{
    int i=0;
    while(i<len)
    {
                if(arr[i]!=arr[0])
                return 1;
                i++;
    }
    return 0;
 
}
