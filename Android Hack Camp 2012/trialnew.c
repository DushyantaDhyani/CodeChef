#include<stdio.h>
#include<conio.h>
int main()
{
    char str[30];
    gets(str);
    char ch;
    int i=0;
    while((ch=str[i])!='\0')
    {
     printf("%c",ch);
     i++;
     }
    getch();
    return 0;    
}
