#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n,q;
  vector<int> v;
  cin>>n;
  for(int i=0;i<n;i++){
    int m;
    cin>>m;
    v.push_back(m);
  }
  cin>>q;
  for(int d=0;d<q;d++){
    int x,low=0,high=(int)v.size()-1;
    bool found=false;
    cin>>x;
    while(low<=high){
      int middle=low+(high-low)/2;
      if(v[middle]>x){high=middle-1;}
      else if(v[middle]<x){low=middle+1;}
      else{cout<<middle<<endl;found=true;break;}
    }
    if(!found){cout<<-1<<endl;}
  }
  return 0;
}