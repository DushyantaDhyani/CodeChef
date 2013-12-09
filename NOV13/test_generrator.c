#include<stdio.h>

int main()
{
   long long i,x,y;
   printf("100\n");
   i=100;
   while(i--)
   {
     x=rand();
     y=x-1;
     while(y<x){
     	y=rand();
     	if(y>x && (y-x)<=1000000){
     		break;
     	}
     }
     printf("%lld %lld\n",x,y);
   }
	return 0;
   }
