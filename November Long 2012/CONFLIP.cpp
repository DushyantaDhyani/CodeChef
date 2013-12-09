#include<iostream>
using namespace std;
class Helper{
      private:
              int G,I,Q;
              long N;
      public:
             Helper();
             void initElements();
             void evaluate();
             long calculate();
};
Helper::Helper(){
           G=0;
           I=0;
           Q=0;
           N=0;      
};
void Helper::initElements(){
     cin>>I>>N>>Q;
}
void Helper::evaluate(){
     cin>>G;
     while(G>0){
               initElements(); 
               cout<<calculate()<<endl;
               G--; 
     }
}
long Helper::calculate(){
     if(N%2!=0){
             if(I==Q){
                  return(N/2);
             }
             else{
                  return ((N/2)+1);
             }
     }
     else{
             return (N/2);
     } 
}
int main(){
    Helper ob;
    int T;
    cin>>T;
    while(T>0){
               ob.evaluate();
               T--;
    }
}
