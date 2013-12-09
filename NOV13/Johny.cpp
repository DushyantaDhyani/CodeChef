#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int T;
    int i,K,N;
    long num;
    scanf("%d",&T);
    while(T>0){
        scanf("%d",&N);
        vector<long> Data(N);
        i=0;
        while(i<N){
            scanf("%ld",&Data[i]);
            i++;
        }
        scanf("%d",&K);
        num=Data[K-1];
        sort(Data.begin(),Data.end());
        i=0;
        while(i<N){
            if(Data[i]==num){
                break;
            }
            i++;
        }
        printf("%d\n",(i+1));
        T--;
    }
    return 0;
}
