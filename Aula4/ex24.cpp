#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,k,m;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    sort(v.begin(),v.end());
    int i=0,d=n-1,res=0;
    while(i<=d){
      if(i==d){res++;break;}
      else if(v[i]+v[d]>k){d--;res++;}
      else {i++;d--;res++;}
    }
    cout<<res<<endl;
    return 0;
}