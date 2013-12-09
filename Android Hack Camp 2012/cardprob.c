#include<stdio.h>
int main()
{
    int T,points,count;
    int i,ctrC,ctrD,ctrH,ctrS;
    char ch;
    scanf("%d",&T);
    int arr[T];
    int k=0;
    points=0;

    while(T>0)
    {
                 ctrC=0;
                 ctrD=0;
                 ctrH=0;
                 ctrS=0;
              i=0;
              count=0;
              points=0;
              fflush(stdin);
              char str[29];
              gets(str);
              while((ch=str[i])!='\0')
              {
              if(ch=='C')
              ctrC++;
              else if(ch=='D')
              ctrD++;
              else if(ch=='H')
              ctrH++;
              else if(ch=='S')
              ctrS++;
              else if((int)ch>=50 && (int)ch<=57)
              points+=(int)ch-48;
              else if((int)ch==49)
              {points+=10;i++;}
              else if(ch=='A')
              points+=11;
              else if((ch=='J') || (ch=='Q') || (ch=='K'))
              points+=10;
              
              i++;
              }
              if(ctrC>0)
              count++;
              if(ctrD>0)
              count++;
              if(ctrH>0)
              count++;
              if(ctrS>0)
              count++;
              if(count==1)
              points+=25;
              else if(count==2)
              points+=10;
              T--;
              arr[k]=points;
              k++;
    }
    i=0;
    while(i<k)
    {
              printf("%d POINTS\n",arr[i]);
              i++;
    }
    return 0;
}
