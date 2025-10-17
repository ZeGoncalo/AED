#include <iostream>

using namespace std;

int main() {
  int n,x,d=0;
  cin >> n >> x;
  int count = 0;
  int m[n];
  for (int i=0; i<n; i++) {
    int a;
    cin >> a;
    if (a != x) {
      count++;
      m[d]=a;
      d++;
    }
  }
  cout << count << endl;
  d=0;
  while (d<count-1) {
    cout<<m[d]<<' ';
    d++;
  }
  cout<<m[d]<< endl;
  return 0;
}