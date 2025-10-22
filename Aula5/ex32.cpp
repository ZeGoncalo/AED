#include <iostream>
#include <cmath>
using namespace std;

long long triangular(long long n) {
    return n * (n + 1) / 2;
}

pair<long long, long long> findPosition(long long n) {
    long long d = (sqrt(8.0 * n + 1) - 1) / 2;
    while (triangular(d) < n) d++;
    long long start = triangular(d - 1) + 1;
    long long offset = n - start;
    return {1 + offset, d - offset};
}

long long sumUntil(long long r, long long c) {
    if (r <= 0 || c <= 0) return 0;
    long double R = r, C = c;
    long double total = R*(R+1)*(R+2*C-1)/6 + R*C*(C-1)/2;
    return (long long)(total + 0.5);  // arredonda para o inteiro mais próximo
}

long long rectangleSum(long long r1, long long c1, long long r2, long long c2) {
    return sumUntil(r2,c2)-sumUntil(r1-1,c2)-sumUntil(r2,c1)+sumUntil(r1-1,c1-1);
}

int main() {
    int n;
    cin >> n;
    while (n>0) {
        long long A, B;
        cin >> A >> B;
        auto [r1, c1] = findPosition(A);
        auto [r2, c2] = findPosition(B);
        n--;
        cout << rectangleSum(r1, c1, r2, c2) << "\n";
    }
}

