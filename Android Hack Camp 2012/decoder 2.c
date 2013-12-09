#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    char str[T][1000];
    int i=0;
    char ch;
    char temp[100];
    
    while(i<T)
    {
              fflush(stdin);
              gets(str[i]);
              i++;
    }
    i=0;
    int pos=0;
    int j=0;
    int k=0;
    while(i<T)
    {
              ch=0;
              j=0;
              k=0;
              pos=0;
              while((ch=str[i][j])!='\0')
              {
                                         if(!(ch>=65 && ch<=90))
                                         {
                                              printf("%c",(str[i][j-3]));
                                              k=pos;
                                              while(k<(j-3))
                                              {
                                                            printf("%c",str[i][k]);
                                                            k++;
                                                            
                                              }
                                              printf("%c",str[i][j]);
                                              pos=j+1;
                                         }
                                         j++;
              }
              printf("\n");
              i++;
    }
    return 0;
}
