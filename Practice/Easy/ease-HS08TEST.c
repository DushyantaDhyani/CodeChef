#include<stdio.h>
int main()
{
    int wdraw;
    float initbal;
    scanf("%d",&wdraw);
    scanf("%f",&initbal);
    if((wdraw%5)!=0)
    printf("%.2f",initbal);
    else if((wdraw+0.5)>initbal)
    printf("%.2f",initbal);
    else
    printf("%.2f",(initbal-(wdraw+0.5)));
    return 0;    
}
