#include<stdio.h>
int main()
{
    int *ptr=NULL;
    int *inp=NULL;
    int ctr=0;
    int num,i;
    scanf("%d",&num);

    while(num!=0)
    {
                 ctr++;

                 ptr=(int *)realloc(ptr,ctr*sizeof(int));
                 inp=(int *)realloc(inp,ctr*sizeof(int));
                 *(ptr+ctr-1)=10000/num;
                 *(inp+ctr-1)=num;
                 scanf("%d",&num);
                 
    }
    i=0;
    while(i<ctr)
    {
                printf("%d GALLONS PER WEEK WILL LAST %d WEEKS\n",inp[i],ptr[i]);
                i++;
    }
   free(inp);
   free(ptr);
    return 0;
}
