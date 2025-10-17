#include <iostream>
using namespace std;
int main(){
  int n,p,a,b;
  cin>>n;
  int seq[n];
  for (int i=0;i<n;i++){
    cin>>seq[i];
  }
  for (int i=1;i<n;i++){
    seq[i]+=seq[i-1];
  }
  cin>>p;
  for (int i=0;i<p;i++){
    cin>>a>>b;
    cout<<seq[b-1]-seq[a-2]<<endl;
  }
  return 0;
}