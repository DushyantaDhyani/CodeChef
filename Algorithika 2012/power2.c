#include<stdio.h>
#include<conio.h>

int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    int i;
    unsigned long int powval;
    for(i=0;i<N;i++)
    scanf("%d",&arr[i]);
    for(i=0;i<N;i++)
    {
     powval=pow(2,i);
     printf("%d\n",sum(powval));
    }
    getch();
    return 0;
}
