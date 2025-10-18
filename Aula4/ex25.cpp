#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int countInversions(vector<int>& v) {
  if (v.size() <= 1) {return 0;}
  int mid = v.size() / 2;
  vector<int> left(v.begin(), v.begin() + mid);
  vector<int> right(v.begin() + mid, v.end());
  int res = countInversions(left) + countInversions(right);
  int i = 0, j = 0, k = 0;
  while (i < (int)left.size() && j < (int)right.size()) {
    if (left[i] <= right[j]) v[k++] = left[i++];
    else {
      v[k++] = right[j++];
      res += left.size() - i;
    }
  }
  while (i < (int)left.size()) v[k++] = left[i++];
  while (j < (int)right.size()) v[k++] = right[j++];
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  cout << countInversions(v) << endl;
}