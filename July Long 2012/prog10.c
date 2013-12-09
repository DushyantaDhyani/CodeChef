#include<stdio.h>
//#include<conio.h>
int main()
{
    int R,C;
    scanf("%d",&R);
    scanf("%d",&C);
    long arr[R][C];
    int i,j,pos,k;
    long small;
    int flag=0;
    for(i=0;i<R;i++)
    {
                    for(j=0;j<C;j++)                
                    {
                                                    scanf("%d",&arr[i][j]);                                
                    }
    }
    i=0;
    while(i<R)
    {
              j=0;
              small=arr[i][0];
              pos=0;
              while(j<C)
              {
                    if(arr[i][j]<small)
                    {
                                        small=arr[i][j];
                                        pos=j;
                    }    
                    j++;
              }
              j=0;
              while(j<C)
              {
                        if(arr[i][j]==small)
                        {
                                     k=0;
                                     while(k<R)
                                     {
                                           if(arr[k][j]>small)
                                           {
                                                   
                                                   break;
                                           }
                                           k++;
                                     }
                                     if(k>=R)
                                     {
                                         printf("%ld",small);
                                         flag=1;
                                         break;
                                     }
                        }
                        
                        j++;
              }
              if(flag==1)
              break;
              i++;
    }
    if(i>=R)
    {
            printf("GUESS");
    }
//    getch();
    return 0;    
}
