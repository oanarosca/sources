#include <iostream>

using namespace std;

int n, p, i, a[20], j;

void reset () {
  for (int i = 1; i <= n; i++)
    a[i] = 0;
}

void baza2 (int n) {
  int i = 0;
  while (n) {
    a[++i] = n % 2;
    n /= 2;
  }
}

int main () {
  cin >> n; p = 1;
  for (i = 1; i <= n; i++)
    p *= 2;
  for (i = 0; i < p; i++) {
    baza2(i);
    for (j = n; j >= 1; j--)
      cout << a[j];
    cout << '\n';
    reset();
  }
  return 0;
}
