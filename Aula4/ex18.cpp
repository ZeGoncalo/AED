#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,k,s;
  cin>>n>>k;
  vector<int> v;
  for (int i=0;i<n;i++){
    cin>>s;
    v.push_back(s);
  }
  sort(v.begin(),v.end(),[](int a, int b){return a>b;});
  for (int i=0;i<k;i++){
    cout<<v[i]<<endl;
  }
  return 0;
}
