#include <iostream>
#include <cmath>

using namespace std;

int i, n, a, r, d, c, divizori, amax, maxd;

int main () {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a; r = (int)sqrt(a); c = a; divizori = 0;
    for (d = 2; d <= r; d++)
      if (c % d == 0) {
        divizori++;
        while (c % d == 0)
          c /= d;
      }
    if (c > 1) divizori++;
    if (divizori > maxd)
      maxd = divizori, amax = a;
    else if (divizori == maxd and a < amax)
      amax = a;
  }
  cout << amax;
  return 0;
}
