#define MAX 1000000000000000000
#include<stdio.h>
int main(){
    long long int num=999999999999999999;
    while(num<=MAX){
        printf("%lld\n",num);
        num++;
    }
    getch();
    return 0;
}
