#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int c1;
  cin>>c1;
  set<int> s;
  for(int i=0;i<c1;i++){
    int n;
    cin>>n;
    s.insert(n);
  }
  int c2;
  cin>>c2;
  bool first=true;
  vector<int> v;
  for(int i=0;i<c2;i++){
    int n;
    cin>>n;
    int b=s.size();
    s.insert(n);
    int a=s.size();
    if(b==a){
      continue;
    }
    v.push_back(n);
  }
  sort(v.begin(),v.end());
  cout<<v.size()<<endl;
  if (v.size()==0){return 0;}
  for (int m : v) {
    if (!first){cout<<' ';}
    first=false;
    cout<<m;
  }
  cout<<endl;
}
