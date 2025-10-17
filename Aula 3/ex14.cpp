#include <iostream>
#include <vector>
using namespace std;
bool isPossible(vector<int>& v,int x, int k){
    int sum=0,i=0,p=0;
    while(i<(int)v.size()){
      sum=0;
      while(sum+v[i]<=x && i<(int)v.size()){
        sum+=v[i];
        i++;
      }
      p++;
      if (p>k){return false;}
    }
    return true;
}

int main(){
  vector<int> d;
  int n,q,p,distance,t=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>distance;
    t+=distance;
    d.push_back(distance);
  }
  cin>>q;

  for (int i=0;i<q;i++){
    int min=1,max=t;
    int x=min+(max-min)/2;
    cin>>p;
    while(min<=max){
      if (!isPossible(d,x,p)){min=x+1;x=min+(max-min)/2;}
      else{max=x-1;x=min+(max-min)/2;}
    }
    cout<<x<<endl;
  }
  return 0;
}