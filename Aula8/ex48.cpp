#include <iostream>
#include <set>
using namespace std;
int main(){
  multiset<int> ms1, ms2;
  int a;
  cin>>a;
  for (int i=0;i<a;i++){
    int n;
    cin>>n;
    ms1.insert(n);
  }
  int b;
  cin>>b;
  for (int i=0;i<b;i++){
    int n;
    cin>>n;
    ms2.insert(n);
  }
  while(!ms1.empty() && !ms2.empty()){
    int n1=*ms1.rbegin();
    int n2=*ms2.rbegin();
    if(n1==n2){
      ms1.erase(--ms1.end());
      ms2.erase(--ms2.end());
    }
    else if(n1>n2){
      ms1.erase(--ms1.end());
      ms2.erase(--ms2.end());
      ms1.insert(n1-n2);
    }
    else{
      ms1.erase(--ms1.end());
      ms2.erase(--ms2.end());
      ms2.insert(n2-n1);
    }
  }
  if(ms1.empty() && ms2.empty()){cout<<"Tie"<<endl<<'0'<<endl;}
  else if(ms1.empty()){cout<<"Bob wins"<<endl<<ms2.size()<<endl;}
  else{cout<<"Alice wins"<<endl<<ms1.size()<<endl;}
}