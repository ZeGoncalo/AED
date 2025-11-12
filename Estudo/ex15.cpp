#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,q;
    vector<int> v,sum;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        v.push_back(m);
    }
    cin>>q;
    for (int i=0;i<(int)v.size()-1;i++){
        for (int d=i+1;d<(int)v.size();d++){
            sum.push_back(v[i]+v[d]);
        }
    }
    sort(sum.begin(), sum.end(),[](int a, int b){return a<b;});
    for(int d=0;d<q;d++){
        int s;
        cin>>s;
        auto it=lower_bound(sum.begin(),sum.end(),s);
        int x=it-sum.begin();
        if(it==sum.end()){cout<<sum[sum.size()-1]<<endl;}
        else if (it == sum.begin()) {cout<<sum[0]<<endl;}
        else if(sum[x]==s){cout<<sum[x]<<endl;}
        else if(sum[x]>s){
            if(sum[x]-s>abs(sum[x-1]-s)){cout<<sum[x-1]<<endl;}
            else if(sum[x]-s<abs(sum[x-1]-s)){cout<<sum[x]<<endl;}
            else{cout<<sum[x-1]<<' '<<sum[x]<<endl;}
        }
    }
}
