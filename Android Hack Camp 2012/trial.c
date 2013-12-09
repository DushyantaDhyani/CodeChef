#include<stdio.h>
#include<conio.h>
int main()
{
    int arr[2];
    arr[0]=4;
    arr[1]=5;
    printf("%d   %d\n",arr[0],arr[1]);
    
    arr[2]=8;
    arr[3]=9;
    printf("%d   %d        %d      %d ",arr[0],arr[1],arr[2],arr[3]);
    printf("%d   %d        %d      %d ",*arr,*(arr+(3.0/2)),*(arr+2),*(arr+3));
    getch();
    return 0;
}
