#include<stdio.h>
#include<conio.h>
int main()
{
    int T;
    scanf("%d",&T);
    char str[T][100];
    int i=0;
    while(i<T)
    {
              gets(str[i]);
              i++;
    }
    getch();
    return 0;
}
