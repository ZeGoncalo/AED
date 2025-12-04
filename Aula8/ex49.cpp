#include <iostream>
#include <map>
using namespace std;
int main(){
  map<int, int> m;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int q;
    cin>>q;
    if(m[q]!=0){cout<<m[q];}
    else{cout<<-1;}
    if (i!=n-1){cout<<' ';}
    m[q]=i+1;
  }
  cout<<endl;
}
