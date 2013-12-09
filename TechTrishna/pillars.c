#include<stdio.h>
#include<conio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int matrix[N][N];
    int i,j,x,y,minrow,mincol,temp,rowpos,colpos,t,k,row;
    for(i=0;i<N;i++)
    {
                    for(j=0;j<N;j++)
                    {
                                    matrix[i][j]=0;
                    }
    }
    for(i=0;i<N;i++)
    {
                    scanf("%d",&x);
                    scanf("%d",&y);
                    matrix[x-1][y-1]=1;
    }
    for(i=0;i<N;i++)
    {
                    for(j=0;j<N;j++)
                    {
                                    printf("%d ",matrix[i][j]);
                    }
                    printf("\n");
    }
    
    //Checking for rows
    minrow=N*(N+1)/2;
    for(k=0;k<N;k++)
    {
                    temp=0;
     for(i=0;i<N;i++)
     {
                    for(j=0;j<N;j++)
                    {
                                    if(matrix[j][i]==1)
                                    {
                                        t=j-k;
                                        if(t<0)
                                        t=t*-1;
                                       temp+=t;
                                    }
                    }
     }
     if(temp<minrow)
     {
                       minrow=temp;
                       rowpos=k;
     }
    }
    //Checking for Columns
    mincol=N*(N+1)/2;
    for(k=0;k<N;k++)
    {
                    temp=0;
     for(i=0;i<N;i++)
     {
                    for(j=0;j<N;j++)
                    {
                                     if(matrix[j][i]==1)
                                    {
                                        t=i-k;
                                        if(t<0)
                                        t=t*-1;
                                        temp+=t;
                                    }

                    }
     }
     if(temp<mincol)
     {
                       mincol=temp;
                       colpos=k;
     }
    }
    if(minrow<mincol)
    {     row=1;
          mincol=minrow;
    }
    else
    {
          minrow=mincol;
          row=0;
    }

    getch();
    return 0;
}
