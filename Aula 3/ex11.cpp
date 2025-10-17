#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n,m,q;
  vector<int> v;
  cin>>n;
  for (int i=0;i<n;i++){cin>>m;v.push_back(m);}
  cin>>q;
  for (int d=0; d<q;d++){
    bool found=false;
    int key;
    cin>>key;
    int low = 0, high = (int)v.size() - 1;
    while (low <= high) {
      int middle = low + (high - low) / 2;
      if (key < v[middle])      high = middle - 1;
      else if (key > v[middle]) low = middle + 1;
      else {cout<< middle<<endl;found=true;break;}
    }
    if (!found){cout<<-1<<endl;}
  }
  return 0;
}
