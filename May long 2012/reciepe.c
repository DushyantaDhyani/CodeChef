#include<stdio.h>
#include<conio.h>
int main()
{
    int N;
    scanf("%d",&N);
    char si[1000];
    long vi=0;
    fflush(stdin);
    gets(si);
    fflush(stdin);
    scanf("%ld",&vi);
    //printf("%s\n",puts(si));
    puts(si);
    printf("\n%ld\n",vi);
    getch();
    return 0;          
}
