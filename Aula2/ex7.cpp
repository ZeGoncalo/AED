#include <iostream>
using namespace std;
int main(){
  int n,s,i,k,res=0;
  char d;
  cin>>n>>s>>i;
  s--;
  char map[n];
  for(int a=0;a<n;a++){
    cin>>map[a];
  }
  int smallest=s,biggest=s;
  for(int m=0;m<i;m++){
    cin>>d>>k;
    if (d=='R'){
      s+=k;
      if (s>biggest){biggest=s;}
    }
    if (d=='L'){
      s-=k;
      if (s<smallest){smallest=s;}
    }
  }
  for (int z=smallest;z<=biggest;z++){
    if (map[z]=='T'){res++;}
  }
  cout<<res<<endl;
  return 0;
}
