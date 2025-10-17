#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string sortString(const string & s){
  string res;
  for(char c:s){
    if(c>='A' && c<='Z'){c='a'+c-'A';}
    if(c==' '){continue;}
    res+=c;
  }
  sort(res.begin(),res.end(),[](char a, char b){return a<b;});
  return res;
}

int main(){
  int n;
  string w;
  vector<string> v;
  cin>>n;
  for(int i=0;i<=n;i++){
    getline(cin,w);
    w=sortString(w);
    v.push_back(w);
  }
  sort(v.begin(),v.end());
  int res=0;
  int i=0;
  while(i<n){
    if(v[i]==v[i+1]){res++;}
    while(v[i]==v[i+1] && i<n-1){i++;}
    i++;
  }
  cout<<res<<endl;
  return 0;
}
