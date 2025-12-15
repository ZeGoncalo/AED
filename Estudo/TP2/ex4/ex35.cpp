#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(){
  int t,n;
  cin>>t;
  cin>>n;
  queue<pair<string,int>> q;
  for(int i=0;i<n;i++){
    string s;
    int m;
    cin>>s;
    cin>>m;
    q.push({s,m});
  }
  int cur=0, i=1;
  while(!q.empty()){
    auto p=q.front();
    q.pop();
    if(p.second<=t){
      cur+=p.second;
      cout<<p.first<<' '<<cur<<' '<<i<<endl;
    }
    else{
      cur+=t;
      p.second=p.second-t;
      q.push(p);
    }
    i++;
  }
}