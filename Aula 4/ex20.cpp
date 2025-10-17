#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,a,l,cur=0,max=0;
  cin>>n;
  vector<pair<int,char>> v;
  for (int i=0;i<n;i++){
    cin>>a>>l;
    v.emplace_back(a,'a');v.emplace_back(l,'l');
  }
  sort(v.begin(),v.end(),[](pair<int,int> a, pair<int,int> b){return a.first<b.first;});
  for (pair h : v){
    if (h.second=='a'){
      cur++;
      if (cur>max){max=cur;}
    }
    if (h.second=='l'){
      cur--;
    }
  }
  cout<<max<<endl;
  return 0;
}
