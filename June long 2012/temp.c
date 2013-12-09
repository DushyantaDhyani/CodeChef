#include<stdio.h>
int checkPrime(long int no);
int main()
{
    long int i=1;
    int ctr=0;
    while(ctr!=1000000)
    {
                   if(checkPrime(i))
                   ctr++;
                   i++;
    }
    i--;
    printf("%ld",i);
    getch();
    return 0;
}
int checkPrime(long int no)
{
    int i=3;
    int limit=sqrt(no);
    if(no==2)
    return 1;
    else if((no%2)==0)
    return 0;
    else
    while(i<=limit)
    {
                   if((no%i)==0)
                   return 0;
                   i=i+2;
    }
    return 1;
}

