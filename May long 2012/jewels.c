#include<stdio.h>
#include<stdlib.h>
int main()
{
    int T,i,j;
    i=1;
    j=0;
    scanf("%d",&T);
    char S[101];
    char J[101];
    int ctr[T];
    while(j<T)
    {
              ctr[j]=0;
              j++;
    }
    char ch;
    int arr[52];
    memset(arr,0,sizeof(arr));
    while(i<=T)
    {
              fflush(stdin);
               gets(J);
              fflush(stdin);
               gets(S);
               j=0;
               memset(arr,0,sizeof(arr));
               while(J[j]!='\0')
               {
                                ch=J[j];
                                if(ch>=65 && ch<=90)
                                arr[ch-65]=1;
                                else 
                                arr[ch-71]=1;                    
                                j++;
               }     
               j=0;
               while(S[j]!='\0')
               {
                                ch=S[j];
                                if(ch>=65 && ch<=90)
                                {
                                          if(arr[ch-65]!=0)
                                          {
                                                       ctr[i-1]++;
                                          }
                                }
                                else
                                {
                                          if(arr[ch-71]!=0)
                                          {
                                                      ctr[i-1]++;
                                                           
                                          }
                                }
                                j++;
                         }
               
               i++;
    }
    j=0;
    while(j<T)
    {
              printf("%d\n",ctr[j]);
              j++;
    }
    return 0;
}
