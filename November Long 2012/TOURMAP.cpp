#include<iostream>
#include<list>
#include<string>
using namespace std;
struct node{
              string str1;
              string str2;
              int cost;
};
class Helper{
      private:
              int size,i;
              long TotalCost;
              string city1,city2;
              int cost;
              node *Node,*tempNode;
              list<struct node*>::iterator loop;
              list<struct node*>::iterator temp;
              list<struct node*> route;
      public:
             Helper(){
                    size=0;
                    i=1;
                    TotalCost=0;
             }
             Helper(int N){
                        size=N;
             }
             void initialize();
             void setList();
             void printList();
};
void Helper::initialize(){
             cin>>city1>>city2>>cost;
             Node=new node();
             Node->str1=city1;
             Node->str2=city2;
             Node->cost=cost;
}
void Helper::setList(){
     while(i<=size){
             initialize();
             if(route.empty()){
                    route.push_front(Node);           
             }
             else{
                  if(city1.compare(route.back()->str2)==0){
                    route.push_back(Node); 
                  }
                  else if(city2.compare(route.front()->str1)==0){
                    route.push_front(Node);   
                  }
                  else{
                       cout<<"Reached Here"<<endl;
                     temp=route.begin();
                     while(temp!=route.end()){
                          cout<<"Printing Values  "<<(*temp)->str1<<"\t"<<(*temp)->str1<<"\t"<<endl;
                          if(city1.compare((*temp)->str2)==0){
                               break;
                          }
                          temp++;                    
                     }
                     if(temp==route.end()){
                           if(city1.compare((*temp)->str2)==0){
                              route.insert(temp,Node); 
                           }
                           else{
                              route.push_back(Node);
                           }
                     }
                     else{
                          route.insert(temp,Node);
                     }
                  }
             }
             i++;            
     }
}
void Helper::printList(){
     TotalCost=0;
     while(!route.empty()){
              Node=route.front();
              cout<<Node->str1<<" "<<Node->str2<<" "<<Node->cost<<endl;
              TotalCost+=Node->cost;
              route.pop_front();                
     }
     cout<<TotalCost<<endl;
}
int main(){
    int T;
    int N;
    cin>>T;
    while(T>0){
          cin>>N;
          Helper ob(N-1);   
          ob.setList();  
          ob.printList();
          T--;
    }
    cin>>T;
}
