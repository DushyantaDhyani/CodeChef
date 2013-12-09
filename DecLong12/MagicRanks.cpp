#include<iostream>
#include<stdio.h>
using namespace std;
class Helper {
    private:
        int **arr;
        int size;
        int tempcost;
        int i,j;
        //int TotalCost;
        float avg;
    public:
        Helper(int x){
            avg=0.0;
            size=x;
            arr=new int*[size];
            i=0;
            while(i<size){
                arr[i]=new int[size];
                i++;
            }
        }
        void getPoints(){
            i=0;
            while(i<size){
                j=0;
                while(j<size){
                    cin>>arr[i][j];
                    j++;
                }
                i++;
            }
        }
        void compute(int x,int y,int cost){
            if(x==size-1 && y==size-1){
                if((cost/(2*size-3))>avg){
                    avg=(cost/(2*size-3))*1.000000;
                }
                return;
            }
            if(y<size-1){
                tempcost=arr[x][y];
                compute(x,y+1,cost+tempcost);
            }
            if(x<size-1){
                tempcost=arr[x][y];
                compute(x+1,y,cost+tempcost);
            }
        }
        void displayMaxCost(){
            if(avg>0)
            //cout<<avg<<endl;
            printf("%f\n",avg);
            else
            cout<<"Bad Judges"<<endl;
        }
};
int main(){
    int T;
    int N;
    cin>>T;
    while(T>0){
        cin>>N;
        Helper ob(N);
        ob.getPoints();
        ob.compute(0,0,0);
        ob.displayMaxCost();
        T--;
    }
}
