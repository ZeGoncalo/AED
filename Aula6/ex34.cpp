#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string p;
    getline(cin,p);
    stack<pair<char,int>> st;
    vector<pair<pair<int,int>,char>> pairs;

    for(int i=0;i<p.size();i++){
        char c=p[i];
        if(c=='(' || c=='{' || c=='['){st.push({c,i});continue;}
        if(c==')' || c=='}' || c==']'){
            if(st.empty()){cout<<"badly matched pairs"<<endl;return 0;}
            char open=st.top().first;
            int pos=st.top().second;
            st.pop();
            if((open=='(' && c==')') || (open=='{' && c=='}') || (open=='[' && c==']')){
                pairs.push_back({{pos,i},open});
            }
            else {cout<<"badly matched pairs"<<endl;return 0;}
        }
    }

    if(!st.empty()){cout<<"badly matched pairs"<<endl;return 0;}
    if(pairs.empty()){cout<<"no brides and grooms to marry"<<endl;return 0;}

    sort(pairs.begin(),pairs.end(),[](pair<pair<int,int>,char> a,pair<pair<int,int>,char> b){return a.first.second<b.first.second;});

    for(int i=0;i<pairs.size();i++){
        if(pairs[i].second=='('){cout<<"() "<<pairs[i].first.first<<' '<<pairs[i].first.second<<endl;}
        if(pairs[i].second=='{'){cout<<"{} "<<pairs[i].first.first<<' '<<pairs[i].first.second<<endl;}
        if(pairs[i].second=='['){cout<<"[] "<<pairs[i].first.first<<' '<<pairs[i].first.second<<endl;}
    }
}
