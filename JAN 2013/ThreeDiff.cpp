#define MAX 1000000009
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int T;
    cin>>T;
    vector<long long int> arr(3);
    long long int FinalVal=0;
    while(T>0){
        cin>>arr[0]>>arr[1]>>arr[2];
                FinalVal=1;

                cout<<FinalVal<<endl;
        T--;
    }
    return 0;
}
