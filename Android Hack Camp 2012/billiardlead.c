#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int lead1[N];
    int pos,max;
    int score1,score2;
    int total1,total2;
    int i=0;
    total1=total2=0;
    while(i<N)
    {
              scanf("%d",&score1);
              scanf("%d",&score2);
              total1+=score1;
              total2+=score2;
              lead1[i]=total1-total2;
              i++;
    }
    i=1;
    pos=0;
    max=lead1[0];
    while(i<N)
    {
       if(lead1[i]<0)
       {
                     if((lead1[i]*-1)>max)
                     {
                                          max=lead1[i]*-1;
                                          pos=i;
                     }
       }
       else
       {

           if(lead1[i]>max)
           {
                           max=lead1[i];
                           pos=i;
           }
       }
       i++;       
    }
    if(lead1[pos]<0)
    {
                    printf("%d %d",2,(lead1[pos]*-1));
    }
    else
    {
        printf("%d %d",1,lead1[pos]);
    }
    return 0;
}
