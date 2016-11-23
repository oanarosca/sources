#include <iostream>

using namespace std;

int n, i, p, a[1100];

void rec (int mij, int n) {
  if (n) {
    a[mij] = n;
    rec ((1+mij)/2, n-1);
    rec ((mij+p)/2+1, n-1);
  }
}

int main () {
  cin >> n; p = 1;
  for (i = 1; i <= n; i++)
    p *= 2;
  p--;
  rec (p/2+1, n);
  for (i = 1; i <= p; i++)
    cout << a[i] << ' ';
  return 0;
}
