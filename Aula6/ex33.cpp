#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n;
    vector<string> v;
    string p;
    getline(cin,p);
    int count=1;
    for (char c:p){if (c==' '){count++;}}
    cin>>n;
    for (int i=0;i<n;i++){
        string w;
        cin>>w;
        v.push_back(w);
    }
    int index=0;
    while (n>1){
        index=(index+count-1)%n;
        cout<<v[index]<<endl;
        v.erase(v.begin()+index);
        n--;
    }
    cout<<v[0]<<endl;
    return 0;
}
