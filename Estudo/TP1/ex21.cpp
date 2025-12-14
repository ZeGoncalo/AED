#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string sortString(string s){
  string res;
    for (char c:s){
      if(c>='A' && c<='Z'){res+='a'+(c-'A');}
      else if(c>='a' && c<='z'){res+=c;}
    }
    sort(res.begin(),res.end());
    return res;
}

int main(){
    int n;
    cin>>n;
    string s;
    vector<string> v;
    for(int i=0;i<=n;i++){
      getline(cin,s);
      s=sortString(s);
      v.push_back(s);
    }
    sort(v.begin(),v.end());
    int res=0,i=1;
    while(i<=n){
      if(v[i]==v[i-1]){
        res++;
        while(v[i]==v[i-1]){i++;}
      }
      i++;
    }
    cout<<res<<endl;
}