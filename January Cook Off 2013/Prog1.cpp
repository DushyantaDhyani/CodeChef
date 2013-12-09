#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int T;
    cin>>T;
    int num1,num2,num3;
    int value=0;
    while(T>0){
        cin>>num1>>num2>>num3;
        if(num3>=(num1+num2)){
            cout<<(num3-(num1+num2))<<endl;
        }
        else if(num2>=(num1+num3)){
            cout<<(num2-(num1+num3))<<endl;
        }
        else if(num1>=(num2+num3)){
            cout<<(num1-(num2+num3))<<endl;
        }
        else{
            cout<<0<<endl;
        }
        T--;
    }
    return 0;
}
