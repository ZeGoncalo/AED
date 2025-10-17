#include <iostream>
#include <vector>
using namespace std;
int lowerBound(const vector<int> & v, int key){
    int low = 0, high = (int)v.size() - 1;
    while (low < high) {
        int middle = low + (high - low) / 2;
        if (v[middle]>=key) {high=middle;}
        else  {low = middle+1;}
    }
    if(v[low]>=key){return low;}
    return -1;
}

int main(){
    int n,m,q;
    vector<int> v;
    cin>>n;
    for (int i=0;i<n;i++){cin>>m;v.push_back(m);}
    cin>>q;
    for (int d=0; d<q;d++){
        int key,res;
        cin>>key;
        res=lowerBound(v,key);
        cout<<res<<endl;
    }
    return 0;
}

