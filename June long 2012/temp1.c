#include<stdio.h>
#include<conio.h>
int main()
{
    long int i=1;
    long int num=15485856;
    while(i<=7742928)
    {
                     if((num%i)==0)
                     printf("%ld     %ld\n",i,(num/i));
                     i++;
    }
    getch();
    return 0;
}
