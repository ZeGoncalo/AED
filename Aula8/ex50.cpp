#include <iostream>
#include <map>
#include <string>
using namespace std;
struct movie {
  int total = 0;
  int positive = 0;
  int negative = 0;
};
int main() {
  int n;
  cin >> n;
  map<string, movie> m;
  for (int i = 0; i < n; i++) {
    string name;
    int score;
    cin >> name >> score;
    movie &mv = m[name];
    mv.total++;
    if (score >= 5)
      mv.positive++;
    else
      mv.negative++;
  }
  cout << m.size() << "\n";
  int maxReviews = 0;
  int countMax = 0;
  for (auto &kv : m) {
    int t = kv.second.total;
    if (t > maxReviews) {
      maxReviews = t;
      countMax = 1;
    } else if (t == maxReviews) {
      countMax++;
    }
  }
  cout << maxReviews << " " << countMax << "\n";
  int morePositive = 0;
  for (auto &kv : m) {
    if (kv.second.positive > kv.second.negative)
      morePositive++;
  }
  cout << morePositive << "\n";
  return 0;
}
