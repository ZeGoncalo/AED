#include <iostream>
#include <map>
using namespace std;
int main(){
  map<int,int> m;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int q;
    cin>>q;
    m[q]++;
  }
  int count=0;
  for(auto& p:m){
    while(p.second!=p.first && p.second!=0){
      p.second--;
      count++;
    }
  }
  cout<<count<<endl;
}