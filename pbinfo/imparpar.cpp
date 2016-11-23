#include <iostream>

using namespace std;

long long n;

long long f (long long n) {
  long long p = 1, i;
  for (i = 1; i <= n; i++)
    p *= i;
  return p;
}

int main () {
  cin >> n;
  if (n % 2 == 0)
    cout << f(n/2)*f(n/2);
  else cout << 0;
  return 0;
}

/*1 2 3 4 5 6

2 1 4 3 6 5 6!
2 1 6 3 4 5 6!

1 2 3*/
