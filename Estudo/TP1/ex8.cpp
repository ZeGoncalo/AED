#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n,k,t;
  cin>>n>>k>>t;
  vector<int> v;
  for(int i=0;i<n;i++){
    int m;
    cin>>m;
    v.push_back(m);
  }
  int b=(k+1)/2,count=0,d=0,res=0;
  while(d<k){
    if(v[d]>=t){count++;}
    d++;
  }
  if(count>=b){res++;}
  for(int i=k;i<n;i++){
    if(v[i-k]>=t){count--;}
    if(v[i]>=t){count++;}
    if(count>=b){res++;}
  }
  cout<<res<<endl;
}