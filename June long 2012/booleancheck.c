#include<stdio.h>
int main()
{
    int abc[10];
    memset(abc,0,sizeof(abc));
    int i=0;
    
    while(i<10)
    {
               printf("%d\n",abc[i]);
               i++;
    }
    getch();
    return 0;
}
