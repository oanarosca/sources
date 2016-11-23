#include <iostream>

using namespace std;

long long n, k;

long long comb (long long n, long long k) {
  long long c1 = 1, c2 = 1, i;

  for (i = k+1; i <= n; i++)
    c1 *= i;
  for (i = 1; i <= n-k; i++)
    c2 *= i;
  return c1/c2;
}

int main () {
  cin >> n >> k;
  cout << comb(n, k);
  return 0;
}

/*n!
(n-k)!*k!

(k+1)*(k+2)*...*n
(n-k)!*/
