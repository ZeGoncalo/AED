#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<pair<string,pair<int,int>>> v;
  v.resize(n);
  for(int i=0;i<n;i++){
    string s;
    int w,d,l,gs,ga;
    cin>>s>>w>>d>>l>>gs>>ga;
    v[i].first=s;
    v[i].second.first=w*3+d;
    v[i].second.second=gs-ga;
  }
  sort(v.begin(),v.end(),[](auto a, auto b){
    if(a.second.first==b.second.first){
      if(a.second.second==b.second.second){return a.first<b.first;}
      return a.second.second>b.second.second;
    }
    return a.second.first>b.second.first;
  });
  for(int i=0;i<n;i++){
    cout<<v[i].first<<' '<<v[i].second.first<<' '<<v[i].second.second<<endl;
  }
  return 0;
}