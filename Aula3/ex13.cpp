#include <iostream>
#include <vector>
using namespace std;
int lowerBound(const vector<int> & v, int key){
    int low = 0, high = (int)v.size();
    while (low < high) {
        int middle = low + (high - low) / 2;
        if (v[middle]>=key) {high=middle;}
        else  {low = middle+1;}
    }
    return low;
}

int higherBound(const vector<int> & v, int key){
    int low = 0, high = (int)v.size();
    while (low < high) {
        int middle = low + (high - low) / 2;
        if (v[middle]>key) {high=middle;}
        else  {low = middle+1;}
    }
    return low;
}

int main(){
    int n,m,q;
    vector<int> v;
    cin>>n;
    for (int i=0;i<n;i++){cin>>m;v.push_back(m);}
    cin>>q;
    for (int d=0; d<q;d++){
        int a,b,low,high;
        cin>>a>>b;
        low=lowerBound(v,a);
        high=higherBound(v,b);
        cout<<high-low<<endl;
    }
    return 0;
}

