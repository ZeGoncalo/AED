#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  cin>>n;
  for (int i=0;i<n;i++){
    int m,c;
    cin>>m;
    c=m;
    cout<<m<<"=";
    while(m%2==0){
      cout<<2;
      m/=2;
      if (m!=1){cout<<'*';}
    }
    for (int d=3;d*d<=m;d+=2) {
      while (m%d==0) {
        cout<<d;
        m/=d;
        if (m!=1){cout<<'*';}
      }
    }
    if (m>1){
      cout<<m;
    }
    cout<<endl;
  }
  return 0;
}