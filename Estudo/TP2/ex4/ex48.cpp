#include <set>
#include <iostream>
using namespace std;
int main(){
  int a, b, e;
  multiset<int> s1,s2;
  cin>>a;
  for(int i=0;i<a;i++){
    cin>>e;
    s1.insert(e);
  }
  cin>>b;
  for(int i=0;i<b;i++){
    cin>>e;
    s2.insert(e);
  }
  while(!s1.empty() && !s2.empty()){
    auto it1=--s1.end();
    auto it2=--s2.end();
    int a1=*it1;
    int b1=*it2;
    s1.erase(it1);
    s2.erase(it2);
    if(a1>b1){
      s1.insert(a1-b1);
    }
    if(a1<b1){
      s2.insert(b1-a1);
    }
  }
  if(s1.empty() && s2.empty()){
    cout<<"Tie"<<endl;
    cout<<s1.size()<<endl;
  }
  else if(s1.empty()){
    cout<<"Bob wins"<<endl;
    cout<<s2.size()<<endl;
  }
  else if(s2.empty()){
    cout<<"Alice wins"<<endl;
    cout<<s1.size()<<endl;
  }
}
