#include <iostream>
#include <list>
#include <string>
using namespace std;
int main(){
  string s;
  getline(cin, s);
  int k=1;
  for(char c:s){if (c==' ')k++;}
  int n;
  cin>>n;
  list<string> l;
  for(int i=0;i<n;i++){
    string name;
    cin>>name;
    l.push_back(name);
  }
  auto z=l.begin();
  while(l.size()!=1){
    for(int i = 1; i < k; i++){
      z++;
      if(z == l.end()) z = l.begin();
    }
    cout<<*z<<endl;
    z=l.erase(z);
    if(z==l.end()){z=l.begin();}
  }
  cout << l.front() << endl;
}
