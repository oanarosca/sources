#include <iostream>

using namespace std;

struct carina {
  char p, d; // pornire, destinatie
};

carina c[100001];
int n, i, a[1001], b[1001], f[1001], op, nb, nc, k, ni;
bool posibil;

int main () {
  cin >> n; ni = n;
  for (i = 1; i <= n; i++)
    cin >> a[i], f[a[i]] = 1;
  k = 1; posibil = true;
  while (posibil) {
    posibil = false;
    if (f[k]) { // pe linia A exista k
      posibil = true;
      for (i = n; ; i--) {
        if (a[i] != k) {
          b[++nb] = a[i]; n--; f[a[i]] = 0;
          c[++op].p = 'A', c[op].d = 'B';
        }
        else {
          f[a[i]] = 0, n--, nc++;
          c[++op].p = 'A', c[op].d = 'C';
          k++; break;
        }
      }
    }
    else
      if (b[nb] == k)
        nb--, c[++op].p = 'B', c[op].d = 'C', nc++, k++, posibil = true;
  }
  if (nc != ni)
    cout << 0;
  else {
    cout << op << '\n';
    for (i = 1; i <= op; i++)
      cout << c[i].p << ' ' << c[i].d << '\n';
  }
}
