#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m;
    vector<int> seq;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>m;
        seq.push_back(m);
    }
    int res=seq[0], cur=0;
    for (int i=0;i<n;i++){
        if(seq[i]>cur+seq[i]){cur=seq[i];}
        else{cur+=seq[i];}
        if(cur>res){res=cur;}
    }
    cout<<res<<endl;
    return 0;
}