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
        int x,low=0,high=(int)v.size();
        cin>>x;
        while(low<high){
            int middle=low+(high-low)/2;
            if(v[middle]>=x){high=middle;}
            else{low=middle+1;}
        }
        if(low==v.size()){cout<<-1<<endl;}
        else{cout<<low<<endl;}
    }
    return 0;
}