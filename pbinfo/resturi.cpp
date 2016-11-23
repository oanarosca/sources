#include <iostream>

using namespace std;

long long n, k, s, s2, r;

int main () {
  cin >> n >> k;
  s = k*(k-1)/2; r = n % k; s2 = r*(r+1)/2;
  cout << s*(n/k)+s2;
  return 0;
}
