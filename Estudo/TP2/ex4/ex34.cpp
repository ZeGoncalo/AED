#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int i=0;
    stack<pair<char, int>> st;
    bool found=false;
    vector<pair<pair<char,char>,pair<int,int>>> v;
    for (char c:s){
      if (c=='(' || c=='{' || c=='['){
        found=true;
        st.push({c,i});
      }
      if (c==')' || c=='}' || c==']'){
        if (st.empty()){cout<<"badly matched pairs"<<endl;return 0;}
        pair<char, int> p=st.top();
        st.pop();
        if((p.first=='(' && c!=')') || (p.first=='{' && c!='}') || (p.first=='[' && c!=']')){
          cout<<"badly matched pairs"<<endl;return 0;
        }
        if((p.first=='(' && c==')') || (p.first=='{' && c=='}') || (p.first=='[' && c==']')){
          v.push_back({{p.first,c},{p.second,i}});
        }
      }
      i++;
    }
    if(!found){cout<<"no brides and grooms to marry"<<endl;return 0;}
    if (!st.empty()){cout<<"badly matched pairs"<<endl;return 0;}
    for(auto z:v){
      cout<<z.first.first<<z.first.second<<' '<<z.second.first<<' '<<z.second.second<<endl;
    }
}
