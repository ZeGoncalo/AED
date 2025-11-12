#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n,s,i;
  cin>>n>>s>>i;
  s--;
  int cur=s,max=s,min=s;
  vector<char> v;
  for(int d=0;d<n;d++){
    char c;
    cin>>c;
    v.push_back(c);
  }
  for(int d=0;d<i;d++){
    char D;
    int k;
    cin>>D>>k;
    if(D=='L'){cur-=k;if(cur<min){min=cur;}}
    if(D=='R'){cur+=k;if(cur>max){max=cur;}}
  }
  int count=0;
  for(int d=min;d<=max;d++){
    if(v[d]=='T'){count++;}
  }
  cout<<count<<endl;
}