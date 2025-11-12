#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  cin>>n;
  int m,s=0;
  vector<int> v;
  v.push_back(0);
  for(int i=0;i<n;i++){
    cin>>m;
    s+=m;
    v.push_back(s);
  }
  cin>>n;
  for(int i=0;i<n;i++){
    int n1,n2;
    cin>>n1>>n2;
    cout<<v[n2]-v[n1-1]<<endl;
  }
  return 0;
}