#include<stdio.h>
int main()
{
          int time[26];
          char str[1000];
          int exe[26];
          gets(str);
          int i=0;
          for(i=0;i<26;i++)
          {
          time[i]=0;
          exe[i]=0;
          }
          char ch;
          i=0;
          while((ch=str[i])!='\0')
          {
          time[ch-97]++;
          i++;
          }
          i=0;
          while((ch=str[i])!='\0')
          {
                                  if(exe[ch-97]==0)
                                  {
                                               printf("%c",ch);
                                               exe[ch-97]=1;
                                               printf("%d",time[ch-97]);
                                  }
                                  i++;
          }
          return 0;
}
