#include <iostream>
#include <cmath>

using namespace std;

int n, d, r;

bool prim (int x) {
  int r = (int)sqrt(x);

  for (int d = 2; d <= r; d++)
    if (x % d == 0) return 0;
  return 1;
}

int main () {
  cin >> n; r = (int)sqrt(n);
  for (d = 2; d <= r; d++)
    if (n % d == 0 and prim(d) and prim(n/d) and d*d != n) {
      cout << "DA"; return 0;
    }
  cout << "NU";
  return 0;
}
