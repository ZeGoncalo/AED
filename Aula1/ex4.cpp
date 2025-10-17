#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i=0;i<n;i++) {
    int a;
    cin>>a;
    cout<<a<<'=';
    while (a%2==0) {
      cout << 2;
      a /= 2;
      if (a!=1) {cout << '*';}
    }
    for (int d=3; d*d<=a; d+=2) {
      while (a % d == 0) {
        cout << d;
        a /= d;
        if (a!=1) {cout << '*';}
      }
    }
    if (a>1) {
      cout<<a;
    }
    cout<<endl;
  }
  return 0;
}