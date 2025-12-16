#include <iostream>
#include <map>
using namespace std;
int main(){
  int n;
  cin>>n;
  map<int, int> m;
  for (int c=0;c<n;c++){
    int s;
    cin>>s;
    m[s]++;
  }
  int i=0;
  for(auto& z:m){
    if(z.first>z.second){
      while(z.second>0){
        i++;
        z.second--;
      }
    }
    if(z.first<z.second){
      while(z.second>z.first){
        z.second--;
        i++;
      }
    }
  }
  cout<<i<<endl;
}