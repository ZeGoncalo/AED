#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,q;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        v.push_back(m);
    }
    cin>>q;
    for(int d=0;d<q;d++){
        int a,b,low=0,high=v.size();
        cin>>a>>b;
        auto it1=lower_bound(v.begin(),v.end(),a);
        auto it2=lower_bound(v.begin(),v.end(),b+1);
        int x1=it1-v.begin();
        int x2=it2-v.begin();
        cout<<x2-x1<<endl;
    }
}