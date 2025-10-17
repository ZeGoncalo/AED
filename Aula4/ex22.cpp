#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  vector<pair<string,vector<int>>> v;
  int n;
  cin>>n;
  v.resize(n);
  for (int i=0;i<n;i++){
    string s;
    int m;
    cin>>s;
    v[i].first=s;
    for (int d=0;d<5;d++){
      cin>>m;
      v[i].second.push_back(m);
    }
  }
  sort(v.begin(),v.end(),[](pair<string,vector<int>> a, pair<string,vector<int>> b){
    if(a.second[0]*3+a.second[1]==b.second[0]*3+b.second[1]){
      if(a.second[3]-a.second[4]==b.second[3]-b.second[4]){return a.first<b.first;}
      return a.second[3]-a.second[4]>b.second[3]-b.second[4];
    }
    else{return a.second[0]*3+a.second[1]>b.second[0]*3+b.second[1];}
  });
  for (int i=0;i<n;i++){
    cout<<v[i].first<<' ';
    cout<<v[i].second[0]*3+v[i].second[1]<<' '<<v[i].second[3]-v[i].second[4]<<endl;
  }
  return 0;
}
