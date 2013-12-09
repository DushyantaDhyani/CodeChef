#include<stdio.h>
int main(){
    int T;
    int G;
    long N;
    int I,Q;
    scanf("%d",&T);
    while(T>0){
               scanf("%d",&G);
               while(G>0){
                          scanf("%d %ld %d",&I,&N,&Q);
                          if(N%2!=0){
                                  if(I==Q){
                                         printf("%ld\n",(N/2));
                                  }
                                  else{
                                         printf("%ld\n",(N/2)+1);
                                  }
                          }
                          else{
                                 printf("%ld\n",(N/2));
                          }
                          G--;
               }
               T--;
    }
    getch();
    return 0;
}
