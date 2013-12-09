#include<stdio.h>
void setDefaultValues(int x,int arr[x][x]);
void getMaze(int x,int arr[x][x]);
void findPaths(int size,int arr1[size][size],int arr2[size][size],int x,int y);
int count=0;
int main(){
    int size;
    scanf("%d",&size);
    int arr[size][size];
    int check[size][size];
    setDefaultValues(size,check);
    getMaze(size,arr);
    findPaths(size,arr,check,0,0);
    printf("%d",count);
    getch();
    return 0;
}
void findPaths(int size,int arr1[size][size],int arr2[size][size],int x,int y){
     if(x==(size-1) && y==(size-1)){
               count++;
               return;
     }
     else{
          arr2[x][y]=1;
          if((x-1)>=0 && arr1[x-1][y]!=1 && arr2[x-1][y]!=1){
                       findPaths(size,arr1,arr2,x-1,y);
          }
          if((y+1)<size && arr1[x][y+1]!=1 && arr2[x][y+1]!=1){
                         findPaths(size,arr1,arr2,x,y+1);
          }
          if((x+1)<size && arr1[x+1][y]!=1 && arr2[x+1][y]!=1){
                         findPaths(size,arr1,arr2,x+1,y);
          }
          if((y-1)>=0 && arr1[x][y-1]!=1 && arr2[x][y-1]!=1){
                       findPaths(size,arr1,arr2,x,y-1);
          }
          arr2[x][y]=0;
     }
}

void setDefaultValues(int x,int arr[x][x]){
     int i=0,j=0;
     while(i<x){
           j=0;     
           while(j<x){
                      arr[i][j]=0;
                      j++;
           }
           i++;
     }
}
void getMaze(int x,int arr[x][x]){
     int i=0,j=0;
     while(i<x){
                j=0;
                while(j<x){
                           scanf("%d",&arr[i][j]);
                           j++;
                }
                i++;
     }
}
