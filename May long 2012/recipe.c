#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    int N;
    scanf("%d",&N);
    char str[N][1001];
    long prio[N];
    int i=0;
    int j;
    char temp[3000];
    char num[1000];
    char chartemp[1];
    while(i<N)
    {
              fflush(stdin);
              gets(temp);
              j=0;
              strcpy(str[i],"");
              strcpy(num,"");
                                  while(temp[j]!=' ')
                                  {
                                                   chartemp[0]=temp[j];
                                                   strcpy(str[i],chartemp);
                                                   j++;
                                  }
                                  j++;
                                  while(temp[j]!='\0')
                                  {
                                                      chartemp[0]=temp[j];
                                                      strcat(num,chartemp);
                                                      j++;
                                  }
              prio[i]=atoi(num);

              i++;
    }
    i=0;
    while(i<N)
    {
              printf("%s",str[i]);
              printf("\n%ld\n",prio[i]);
              i++;
    }
    getch();
    return 0;
}
