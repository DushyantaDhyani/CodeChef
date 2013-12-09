#include<stdio.h>
//#include<conio.h>
int main()
{
    int T;
    scanf("%d",&T);
    int output[T];
    int i,N,j;
    long int C;
    long int sum;
    int temp;
    i=0;
    while(i<T)
    {
              scanf("%d",&N);
              scanf("%ld",&C);
              j=0;
              sum=0;
              temp=0;
              while(j<N)
              {
                  scanf("%d",&temp);
                 sum=sum+temp;
                 j++;       
              }
              if(sum<=C)
              output[i]=1;
              else
              output[i]=0;
              i++;
    }
    i=0;
    while(i<T)
    {
              if(output[i]==1)
              printf("Yes\n");
              else
              printf("No\n");
              i++;
    }
//    getch();
    return 0;    
}
