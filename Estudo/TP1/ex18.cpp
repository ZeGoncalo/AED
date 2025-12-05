#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,k;
    vector<int> v;
    cin>>n>>k;
    for(int i=0;i<n;i++){
      int s;
      cin>>s;
      v.push_back(s);
    }
    sort(v.begin(),v.end(),[](int a, int b){return a>b;});
    for(int i=0;i<k;i++){
      cout<<v[i]<<endl;
    }
}