#include<iostream>
using namespace std;
class Helper{
      private:
            int X,Y;
            int NB,NOB;
            int i,j;
            int dir;
            int posx,posy;
            int var1,var2,var3;
            float speed;
            int **arr,**temparr;
            int Points;
      public:
             Helper();
            Helper(int x,int y,int q,int w);
            void setPins();
            void setBumpers();
            int findPoints();
            void testInput();
};
Helper::Helper(){
               i=0;  
               X=0;
               Y=0;
               NB=0;
               NOB=0;
               speed=0.0f;
               var1=var2=var3=0;
               arr=NULL;
}
      
Helper::Helper(int x,int y,int q,int w){
                   X=x;
                   Y=y;
                   NB=q;
                   NOB=w;
                   arr=new int*[X];
                   i=0;
                   while(i<X){
                              arr[i]=new int[Y];
                              i++;
                   }
}
void Helper::setPins(){
     i=0;
     while(i<X){
                j=0;
                while(j<Y){
                           arr[i][j]=0;
                           j++;
                }
                i++;
     }
}
void Helper::setBumpers(){
     i=1;
     while(i<=NB){
                  cin>>var1>>var2>>var3;
                  arr[var2][var1]=var3;
                  i++;
     }
     memcpy(temparr,arr,sizeof(arr));
}
int Helper::findPoints(){
    Points=0;
    dir=var3;
    posx=var2;
    posy=var1;
    while(speed>0){
                   if(temparr[posx][posy]==-1){
                       speed-=0.5;
                       setCoordinates(-1);
                   }
                   if(temparr[posx][posy]==0){
                              Points+=1;
                              speed-=1;
                              setCoordinates(0);                
                   }
                   if(temparr[posx][posy]>0){
                              Points+=temparr[posx][posy];
                              Speed-=1.5;
                              setCoordinates(1);               
                   }
                   if(dir==0 && posx==0){
                             dir=2;
                   }
                   if(dir==2 && posx==(X-1)){
                             dir=0;
                   }
                   if(dir==1 && posy==(Y-1)){
                             dir=3;
                   }
                   if(dir==3 && posy==0){
                             dir=1;
                   }
                   
    }
    memcpy(temparr,arr,sizeof(arr));
}
void Helper::setCoordinates(int x){
          if(x==-1 || x==0){
                    if(dir==0 && (posx-1)>=0){
                               posx--;
                    }
                    if(dir==2 && (posx+1)<X){
                              posx++;
                    }
                    if(dir==1 && (posy+1)<Y){
                              posy++;
                    }
                    if(dir==3 && (posy-1)>=0){
                              posy--;
                    }
          }
          else if(x==1){
               if()
          }
}
void Helper::testInput(){
     i=1;
     while(i<=NOB){
                 cin>>var2>>var1>>var3>>speed;
                 cout<<findPoints()<<endl;
                 i++;
     }
}
int main(){
    int N,M,Q,W;
    cin>>N>>M>>Q>>W;
    Helper ob(M,N,Q,W);    
    ob.setPins();
    ob.setBumpers();
    ob.testInput();
}
