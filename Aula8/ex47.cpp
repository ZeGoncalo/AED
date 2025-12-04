#include <iostream>
#include <set>
using namespace std;
int  main(){
  int c;
  cin>>c;
  set<int> s,r;
  for (int i=0;i<c;i++){
    int c1;
    cin>>c1;
    s.insert(c1);
  }
  int b;
  cin>>b;
  for (int i=0;i<b;i++){
    int b1;
    cin>>b1;
    int l1 =s.size();
    s.insert(b1);
    int l2= s.size();
    if(l1!=l2){
      r.insert(b1);
    }
  }
  cout<<r.size()<<endl;
  int count=0;
  if (r.size()!=0){
    for (int n : r){
      count++;
      cout<<n;
      if (count!=r.size()){cout<<' ';}
    }
    cout<<endl;
   }
}
