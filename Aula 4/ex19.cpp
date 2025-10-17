#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countOnes(int n){
  int s=0;
  while(n>0){
    if(n%2==1){s++;}
    n/=2;
  }
  return s;
}

int main(){
  int n,s;
  cin>>n;
  vector<int> v,b;
  for (int i=0;i<n;i++){
    cin>>s;
    v.push_back(s);
  }
  sort(v.begin(),v.end(),[](int a, int b){if (countOnes(a)!=countOnes(b)){return countOnes(a)>countOnes(b);};return a<b;});
  for (int i=0;i<n;i++){cout<<v[i]<<endl;}
  return 0;
}
