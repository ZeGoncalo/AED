#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,k,t,m,res=0;
    cin>>n>>k>>t;
    vector<int> r;
    for (int i=0;i<n;i++) {
        cin>>m;
        r.push_back(m);
    }
    int b=(k+1)/2, count=0, d=0;
    while (d<k) {
        if (r[d]>=t){count++;}
        d++;
    }
    if (count>=b){res++;}
    for (int i=k;i<n;i++) {
        if (r[i-k]>=t) {count--;}
        if (r[i]>=t) {count++;}
        if (count<b){continue;}
        res++;
    }
    cout<<res<<endl;
    return 0;
}