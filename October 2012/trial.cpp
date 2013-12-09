// partial_sort example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction (int i,int j) { return (i<j); }

int main () {
  int myints[] = {9,8,7,6,5,4,3,2,1};
  vector<int> myvector (myints, myints+9);
  vector<int>::iterator it;

  // using default comparison (operator <):
  partial_sort (myvector.begin()+2, myvector.begin()+5, myvector.end());

  // using function as comp
  partial_sort (myvector.begin()+2, myvector.begin()+5, myvector.end(),myfunction);

  // print out content:
  cout << "myvector contains:";
  for (it=myvector.begin(); it!=myvector.end(); ++it)
    cout << " " << *it;

  cout << endl;
  int i;
  cin>>i;
  return 0;
}
