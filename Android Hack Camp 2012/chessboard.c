#include<stdio.h>
int main()
{
    int T,N;
    
    int x,y;
    x=0;
    y=0;
    int i=0;
    int count=0;
    int up,left,right,down;
    scanf("%d",&T);
    int arr[T];
    N=T;
    while(T>0)
    {
              count=0;
              x=0;
              y=0;
              fflush(stdin);
              scanf("%c",&x);
              scanf("%d",&y);
              x=x-97+1;
              up=8-y;
              down=y-1;
              left=x-1;
              right=8-x;
              if(up>1)
              {
                                if(right>=2)
                                count+=2;
                                else if(right==1)
                                count++;
                                if(left>=2)
                                count+=2;
                                else if(left==1)
                                count++;
               }
               else if(up==1)
               {
                    if(right>=2)
                    count++;
                    if(left>=2)
                    count++;
               
               }
               if(down>1)
               {
                          if(right>=2)
                          count+=2;
                          else if(right==1)
                          count++;
                          if(left>=2)
                          count+=2;
                          else if(left==1)
                          count++;
               }
               else if(down==1)
               {
                    if(right>=2)
                    count++;
                    if(left>=2)
                    count++;
               }
               arr[i]=count;
               i++;
              T--;
    }
    i=0;
    while(i<N)
    {
              printf("%d\n",arr[i]);
              i++;
    }
    return 0;
}
