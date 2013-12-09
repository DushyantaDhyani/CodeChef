#include<stdio.h>
#include<conio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int x[N];
    int y[N];
    int i=0;
    int i,j,k;
    int quad1,quad2,quad3,quad4;
    quad1=quad2=quad3=quad4=0;
    while(i<N)
    {
              scanf("%d",&x[i]);
              scanf("%d",&y[i]);
              if(x[i]>=0)
              {
                       if(y[i]>=0)
                       quad1++;
                       else
                       quad4++; 
              }
              else
              {
                  if(y[i]>=0)
                       quad2++;
                       else
                       quad3++; 
              }
              
              i++;
    }
    for(i=0;i<=n-3;i++)
    {
                       for(j=0;j<=n-2;j++)
                       {
                                          for(k=0;k<=n-1;k++)
                                          {
                                                             
                                          }
                       }
    }
    getch();
    return 0;
}
