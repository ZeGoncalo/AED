#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<pair<int,int>> v;
  for(int i=0;i<n;i++){
    int m,t;
    cin>>m;
    t=m;
    int count=0;
    while(m>0){
      if(m%2==1){count++;}
      m/=2;
    }
    v.emplace_back(t, count);
  }
  sort(v.begin(),v.end(),[](auto a, auto b){if(a.second==b.second){return a.first<b.first;}return a.second>b.second;});
  for (int i=0;i<n;i++){
    cout<<v[i].first<<endl;
  }
  return 0;
}
