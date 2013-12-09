#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void enter(long int arr[],long int size);
int check(long int num);
int main()
{
    int T;
    long int j;
    scanf("%d",&T);
    int i=1;
    while(i<=T)
    {
               printf("%d",i);
      long int n=0;
      long int len=0;
      scanf("%ld",&n);
      
      long int arr[n];
      for(j=0;j<n;j++)
      arr[j]=0;

      enter(arr,n);
      long int t=n;
      long int k;
      while(t>2)
      {
        len=0;        
        long int pos[t];
        for(j=0;j<t;j++)
        pos[j]=0;
        for(k=0;k<t;k++)
        {
                        if(check(k+1)!=1)
                        {
                         pos[k]=1;
                        
                         len++;
                        }
        }
        long int *temp=(long int *) malloc(len * sizeof (long int));
        j=0;
        for(k=0;k<t;k++)
        {
                        if(pos[k]==1)
       
                        {
                        temp[j]=arr[k];
                        j++;
                        }
        }
        
        long int *arr =(long int*)realloc(arr,len*sizeof(long int) );
        for(j=0;j<len;j++)
        {
         arr[j]=temp[j];
        
        }
        free(temp);
        t=len;
        
      }      
      if(t==2)
      printf("%d %d",arr[0],arr[1]);
      else if(t==1)
      printf("%d",arr[0]);      
     i++;
    }
    getch();
 return 0;
}
void enter(long int arr[],long int size)
{
     long int j=0;
     while(j<size)
     {
                  scanf("%ld",&arr[j]);
                  j++;
     }
}
int check(long int num)
{
 int j=0;
 long int val=0;
 while(val<=num)
 {
  val=pow(2,j);
  j++;
  if(val==num)
  return 1;
 }
 return 0;
}
