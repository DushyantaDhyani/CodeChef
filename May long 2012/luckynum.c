#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    int i=0;
    long j=0;
    long output[T];
    long N;
    while(i<T)
    {
              output[i]=-1;
              i++;
    }
    i=0;
    while(i<T)
    {
              scanf("%ld",&N);
              j=0;
              while((N-4*j)>=0)
              {
                               if(((N-4*j)%7)==0)             
                               {
                                output[i]=(N-4*j);
                                break;
                               }
                               
                               j++;
              }

              
              i++;
    }
    i=0;
    while(i<T)
    {
              printf("%ld\n",output[i]);
              i++;
    }
    return 0;    
}
