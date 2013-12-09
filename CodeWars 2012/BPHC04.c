#include<iostream>
using namespace std;
class Helper{
      int X,Y;
      Helper(){
               X=0;
               Y=0;
      }
}
Helper::Helper(int x,int y){
                   X=x;
                   Y=y;
}
int main(){
    int N,M,Q,W;
    cin>>N>>M>>Q>>W;
    Helper ob(M,N);    
}
