#include <iostream>

using namespace std;

int n, i, m, x, a[25005];

int cb (int x) {
  int m, p = 1, u = n;
  while (p <= u) {
    m = (p+u)/2;
    if (a[m] == x)
      return 1;
    else
      if (a[m] < x)
        p = m+1;
      else
        u = m-1;
  }
  return 0;
}

int main () {
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> a[i];
  cin >> m;
  for (i = 1; i <= m; i++)
    cin >> x, cout << cb(x) << ' ';
  return 0;
}
