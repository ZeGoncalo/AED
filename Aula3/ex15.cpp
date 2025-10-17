#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,m,q,s;
  vector<int> v,sums;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>m;
    v.push_back(m);
  }
  for (int i=0;i<(int)v.size()-1;i++){
    for (int d=i+1;d<(int)v.size();d++){
      sums.push_back(v[i]+v[d]);
    }
  }
  sort(sums.begin(),sums.end(),[](int a, int b){return a<b;});
  cin>>q;
  for (int i=0;i<q;i++){
    int low = 0, high = (int)sums.size()-1;
    cin>>s;
    bool found=false;
    while (low <= high) {
      int middle = low + (high - low) / 2;
      if (sums[middle]>s) {high=middle-1;}
      else if (sums[middle]<s)  {low = middle+1;}
      else {cout<<sums[middle]<<endl;found=true;break;}
    }
    if (found){continue;}
    if (low >= (int)sums.size()) low = (int)sums.size() - 1;
    if (high < 0) high = 0;
    if (low==high){cout<<sums[low]<<endl;continue;}
    int best1=sums[low],diff1=abs(s-sums[low]),best2=sums[high],diff2=abs(s-sums[high]);
    if (diff1 < diff2) {
      cout << best1 << endl;
    }
    else if (diff2 < diff1) {
      cout << best2 << endl;
    }
    else if (diff1 == diff2) {
      if (best1 < best2) cout << best1 << " " << best2 << endl;
      else cout << best2 << " " << best1 << endl;
    }
  }
  return 0;
}
