#include<stdio.h>
void enter(int arr[],int N);
void merge_sort(int arr[],int low,int high);
void sort(int arr[],int l,int m,int h);
int permute(int x,int y);
int fact(int t);
int main()
{
	int N,size;
	scanf("%d",&N);
	int val[N];
	size=N;
	int t=0;
	int j=0;
	int i=0;
	int ret_val=0;
	while(N>0)
	{
              int arr[11];
	 enter(arr,11);
	 scanf("%d",&t);
	 merge_sort(arr,0,10);
	 ret_val=compute(arr,11,t);
	 val[j++]=ret_val;
	 N--;
    } 
    while(i<size)
    {
                 printf("%d\n",val[i]);
                 i++;
    }
	return 0;
}
void enter(int arr[],int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);	
	}
}
void merge_sort(int arr[],int low,int high)
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
void sort(int arr[],int low,int mid,int high)
{
	int temparr[high-low+1];
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
int compute(int arr[],int lim,int x)
{
 int i=9;
 int cur=arr[10];
 int ctr=0;
 while(i>=0)
 {
            ctr=1;
            while(arr[i]==cur)
            {
                              ctr++;
                              i--;
            }
            if((x-ctr)==0)
            {
                          return 1;
            }
            else if((x-ctr)<0)
            {
                 return permute(ctr,x);
            }
            else
            {
                      x=x-ctr;        
                     cur=arr[i];
                     i--;
            }
 }   
}
int permute(int x,int y)
{
    int s=fact(x);
    int p=fact(y);
    int d=fact(x-y);
    return s/(p*d);
}
int fact(int t)
{
    int fact=1;
    while(t>0)
    {
              fact=fact*t;
              t--;
    }
    return fact;
}
