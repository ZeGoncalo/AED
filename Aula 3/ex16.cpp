#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool canRemove(int k,string i,string f, vector<int> p) {
    int n=(int)i.size();
    vector removed(n, false);
    for (int d=0; d<k; d++) {removed[p[d]-1]=true;}
    int j=0;
    for (int d=0; d<n && j<(int)f.size(); d++) {
        if (!removed[d] && i[d]==f[j]) {j++;}
    }
    return j==(int)f.size();
}

int main() {
    string i,f;
    cin>>i>>f;
    vector<int> p;
    int n=(int)i.size(),m;
    for (int d=0; d<n; d++) {
      cin>>m;
      p.push_back(m);
    }
    int low=0, high=n, ans=0;
    while (low<=high) {
        int mid=(low+high)/2;
        if (canRemove(mid,i,f,p)) {
            ans=mid;
            low=mid+1;
        }
        else{high = mid - 1;}
    }
    cout<<ans<<endl;
    return 0;
}
