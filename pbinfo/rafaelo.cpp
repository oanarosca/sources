#include <iostream>

using namespace std;

int s, n, i, p, maxim, mag;

int main () {
  cin >> s >> n;
  for (i = 1; i <= n; i++) {
    cin >> p;
    if (s/p > maxim)
      maxim = s/p, mag = i;
  }
  cout << maxim << ' ' << mag;
  return 0;
}
