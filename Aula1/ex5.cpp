#include <iostream>
#include <cmath>
using namespace std;
int main() {
  long n;
  cin>>n;
  if (n==1) {
    cout<<"(0,0)"<<endl;
    return 0;
  }

  long a=ceil((sqrt(n)-1)/2.0);
  long max=(2*a+1)*(2*a+1);
  long offset=max-n;
  long l=2*a;
  long x, y;
  if (offset<l) {
    x=a-offset;
    y=a;
  }
  else if (offset<2*l) {
    x=-a;
    y=a-(offset-l);
  }
  else if (offset<3*l) {
    x=-a+(offset-2*l);
    y=-a;
  }
  else {
    x=a;
    y=-a+(offset-3*l);
  }
  cout<<'('<<x<<','<<y<<')'<<endl;
  return 0;
}

