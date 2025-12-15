#include <iostream>
#include <map>
using namespace std;
int main(){
  int n;
  cin>>n;
  map<int,int> s;
  for(int i=0;i<n;i++) {
    int m;
    cin>>m;
    if (s[m]==0){cout<<-1;s[m]=i+1;}
    else{cout<<s[m];s[m]=i+1;}
    if (i!=n-1){cout<<' ';}
  }
  cout<<endl;
}
