#include<stdio.h>
int main()
{
    char str1[40];
    char str2[40];
    gets(str1);
    gets(str2);
    int i=0;
    int j=0;
    int spam=0;
    char ch,ch1;
    while((ch=str1[i])!='\0')
    {
                             while((ch=str1[i])!=str2[0])
                             {
                                                         if(ch!='\0')
                                                         i++;
                                                         else
                                                         break;
                             }
                             if(ch=='\0')
                             {
                                         printf("N");
                                         break;
                             }
                             else
                             {
                                         j=0;
                                         while((ch1=str2[j])!='\0')
                                         {
                                                                   ch=str1[i];
                                                                   if(ch==ch1)
                                                                   {i++;j++;}
                                                                   else
                                                                   break;
                                         }
                                         if(ch1=='\0')
                                         {
                                                      printf("Y");
                                         
                                                      spam=1;
                                                                   break;
                                         }
                                         if(spam==1)
                                         break;
                             
                             }
    }
 return 0;
}
