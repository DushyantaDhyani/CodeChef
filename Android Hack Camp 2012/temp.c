#include<stdio.h>
#include<conio.h>
int main()
{
    int T;
    int arr[T];
    int x,y;
    x=y=0;
    int i=0;
    int count=0;
    int up,left,right,down;
    scanf("%d",&T);
    while(T>0)
    {
              count=0;
              scanf("%c",&x);
              scanf("%d",&y);
              x=x-97+1;
              up=8-y;
              down=y-1;
              left=x-1;
              right=8-x;
              if(up>=1)
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
               if(down>=1)
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
               arr[i]=count;
               i++;
              T--;
    }
    i=0;
    while(i<T)
    {
              printf("%d\n",arr[i]);
              i++;
    }
    getch();
    return 0;
}
