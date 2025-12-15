#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Client{
  public:
  string name;
  int arrival;
  int products;
  int start;
  int departure;
};
class Checkout{
  public:
  int n;
  int speed;
  int clients=0;
  vector<Client> v;
};
class Supermarket{
  public:
  vector<Checkout> s;
};

int main(){
  int c;
  cin>>c;
  Supermarket loja;
  for (int i=0;i<c;i++){
    Checkout c;
    int speed;
    cin>>speed;
    c.n=i+1;
    c.speed=speed;
    loja.s.push_back(c);
  }
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    Client cl;
    string name;
    int a,p;
    cin>>name>>a>>p;
    cl.name=name;
    cl.arrival=a;
    cl.products=p;
    for (Checkout& c1 : loja.s) {
      int n1=c1.v.size();
      for (Client& cl1 : c1.v){
        if (cl1.departure<a) {
          n1--;
        }
      }
      c1.clients=n1;
    }
    sort(loja.s.begin(), loja.s.end(), [](const Checkout& a, const Checkout& b) {
      if (a.clients != b.clients)
        return a.clients < b.clients;
      if (a.clients==0)
        return a.n < b.n;
      if (a.v.back().products != b.v.back().products)
        return a.v.back().products < b.v.back().products;
      return a.n < b.n;
    });
    Checkout& cur=loja.s[0];
    if(cur.v.empty()){
      cl.start=a;
      cl.departure=cl.start+10+cur.speed*p;
      cur.v.push_back(cl);
      cur.clients++;
    }
    else{
      if(cur.v[cur.v.size()-1].departure>a){
        cl.start=cur.v[cur.v.size()-1].departure;
      }
      else{
        cl.start=a;
      }
      cl.departure=cl.start+10+cur.speed*cl.products;
      cur.v.push_back(cl);
      cur.clients++;
    }
  }
  sort(loja.s.begin(),loja.s.end(),[](auto a, auto b){return a.n<b.n;});
  for (Checkout z : loja.s){
    cout<<"Checkout #"<<z.n<<": "<<z.v.size()<<endl;
    for(Client w:z.v){
      cout<<". "<<w.name<<' '<<w.arrival<<' '<<w.start<<' '<<w.departure<<endl;
    }
  }
}