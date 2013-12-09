#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    int i=0;
    int k;
    char str[101];
	char output[T][101];
    int len,j,s;
	char ch;
	char noop[3]={'N','O'};
    while(i<T)
    {
              scanf("%d",&k);
              fflush(stdin);
              gets(str);
              j=0;  
              while(str[j]!='\0')
              {
                               
                                 j++;
              }
              len=j;
              if(len==1)
			  {
				if(str[0]!='?')
				{
                    if((str[0]-48)<k)
                    {
					  strcpy(output[i],str);
                    }
                    else
                    {
                        strcpy(output[i],noop);
                    }
                }
				else
				{
                    str[0]='0';
                    strcpy(output[i],str);
                }
			  }
              else if((str[0]==str[len-1]) && str[0]!='?')
              {
                  strcpy(output[i],noop);
                  
              }
              else
              {
                  j=0;
                  while(j<len-1)
                  {
                                if(str[j]==str[j+1])
                                {
                                                    if(str[j]!='?')
                                                    {
                                                                  strcpy(output[i],noop);
                                                                  break;
                                                    }
                                }
                                j++;
                  }
                  if(j<(len-1))
                  continue;
				  if(str[0]=='?')
				  {
						s=0;
									while(s<k)
									{
												ch=s+48;
												if((str[len-1]!=ch) && str[1]!=ch)
												{
													str[0]=ch;
													break;
													
												}
												s++;
									}
									
				  }
                  
                  j=1;
                  while(j<len-1)
                  {
                              if(str[j]=='?')
							  {
									s=0;
									while(s<k)
									{
												ch=s+48;
												if((str[j-1]!=ch) && str[j+1]!=ch)
												{
													str[j]=ch;
													break;
												}
												s++;
									}
									if(s>=k)
									{
										strcpy(output[i],noop);
										break;
									}
									
							  }
							  j++;
                  }
				  if(s>=k)
				  continue;
				  if(str[len-1]=='?')
				  {
						s=0;
									while(s<k)
									{
												ch=s+48;
												if((str[len-2]!=ch) && str[0]!=ch)
												{
													str[len-1]=ch;
													break;
												}
												s++;
									}
									if(s>=k)
									{
										strcpy(output[i],noop);
                                        continue;
									}
									
				  }
                  strcpy(output[i],str);
              }
              i++;
    }
	i=0;
	while(i<T)
	{
			printf("%s\n",output[i]);
			i++;
	}
    getch();
    return 0;
}
