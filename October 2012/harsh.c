#include<stdio.h>
#include<conio.h>
int count;
int fun(int open,int close,int n)
{
 	if(close<=n && open<=n)
 	{
 	 if(open==n&&close==n){	
			count++;
			return 0;
     }
 	 else
 	 {
	  	 if(open>close)
	  	 fun(open,close+1,n);
	  	 
	  	 fun(open+1,close,n);
     }
   }
}
	  	 
int main()
{
 	 fun(0,0,4);
	 printf("%d",count);
	 getch();
}
