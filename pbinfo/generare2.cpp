#include <iostream>

using namespace std;

int n, a, x, y, i, b[1000001];

void adauga (int a) {
  if (a <= n and not b[a]) {
    b[a] = 1;
    adauga (a+x); adauga (a+y);
  }
}

int main () {
  cin >> n >> a >> x >> y;
  adauga(a);
  for (i = 0; i <= n; i++)
    if (b[i] == 1)
      cout << i << ' ';
  return 0;
}
