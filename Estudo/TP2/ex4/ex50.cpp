#include <iostream>
#include <map>
#include <string>
using namespace std;
class Movie{
  public:
  int n=0;
  int positive=0;
  int negative=0;
};
int main(){
  map<string,Movie> m;
  int n, r;
  string s;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s;
    cin>>r;
    if(r>=5){m[s].positive++;}
    else{m[s].negative++;}
    m[s].n++;
  }
  int t=0, max=0, nmax=0, pn=0;
  for(auto z : m){
    t++;
    if (z.second.positive>z.second.negative){pn++;}
    if (z.second.n>max){max=z.second.n; nmax=0;}
    if (z.second.n==max){nmax++;}
  }
  cout<<t<<endl<<max<<' '<<nmax<<endl<<pn<<endl;
}