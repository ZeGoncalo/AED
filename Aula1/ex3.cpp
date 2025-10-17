#include <iostream>
using namespace std;
int main() {

    int n;
    cin >> n;
    int count = 0, last=-1;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a%2==1) {
          count++;
          last=a;
        }
    }

    cout << count << ' ' << last<<endl;

    return 0;
}