#include<stdio.h>
#include<math.h>
int f_arr[10000001];
int a[500001];
int g_count;
char check[1000001];
int k=0;
int func(int n)
{
    a[2]=0;
    int i,j;
    int p=(int)sqrt(n);
   for(i=0;i<n;i++)
   check[i]='0';
   check[0]=check[1]='1';
    for(i=2;i<p;i++)
    {
       if(check[i]=='0')
       {
           for(j=i*i;j<n;j=j+i)
           {
               check[j]='1';
           }

    //printf("%d\n",i);
       }

    //printf("etest");
    }
    k=0;

    //printf("etest");
    for(i=2;i<n;i++)
    {
        if(check[i]=='0')
        {
            a[k++]=i;
        }

    //printf("etest");

    }
}
void count(long long a,long long b)
{
    long long i;
   //printf("ab %lld %lld  \n ",a,b);
    for(i=a;i<=b;i++)
    if(check[i+1]=='0')
    g_count++;
}
void ans(long long b,long long c)
{
    long long i=0,j;

        float min,max;
        while(1)
        {
            min=log(b)/log(a[i]);
            max=log(c)/log(a[i]);
            if(min-(int)min>0)
            min=(int)min+1;
           //printf(" min max %f %f prime no %d\n",min,max,a[i]);

            if(max<1)
            break;
            if(min<2)
            min=2;
            count((int)min,(int)max);
            i++;
        }

}
void display()
{
    int i;
    //for(i=0;i<=k;i++)
    printf("%d ",k);
}
void prime(long long b,long long c,int f_arr[])
{
    long long j,i,z;
    //printf("bck  %lld\n",b,c,k);
    for(i=0;i<k&&a[i]<=c;i++)
    {
        j=b/a[i];
        z=j*a[i];
        if(z<b)
        z=z+a[i];
        if(z==a[i])
        z+=a[i];

        while(z<=c)
        {
           // printf("z %d\n",z);
            f_arr[z-b]=1;
            z+=a[i];
        }

    }
}
int main()
{
    int t,i,j;
    long long b,c;
    scanf("%d",&t);
     func(1000001);
    // display();
    while(t--)
    {
        scanf("%lld %lld",&b,&c);

        for(i=0;i<=c-b;i++)
         f_arr[i]=0;

        ans(b,c);

         prime(b,c,f_arr);


         if(b==1)
          f_arr[0]=1;
        //display(b,c,f_arr);
        for(i=0;i<=c-b;i++)
        {
            if(f_arr[i]==0)
            {
            g_count++;
            }
        }
        printf("%d\n",g_count);
        g_count=0;
    }
    return 0;
}
