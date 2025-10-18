#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,k,m,min=1000000;
  cin>>n>>k;
  vector<int> v;
  for (int i=0;i<n;i++){
    cin>>m;
    v.push_back(m);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i <= n - k; i++) {
    int diff = v[i + k - 1] - v[i];
    if (diff < min) {min = diff;}
  }
  cout<<min<<endl;
  return 0;
}
