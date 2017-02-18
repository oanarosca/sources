nclude <fstream>
#include <cstdlib>

using namespace std;

int n, c, maxim, minim, i, j, f[10], cont;

int main () {
  ifstream fi("cifru5.in");
  ofstream fo("cifru5.out");
  fi >> j;
  for (i = 1; i <= j; i++) {
    fi >> c;
    if (c > maxim)
      maxim = c;
    for (n = 0; n <= 9; n++)
      if (c < n)
        f[n] += min(abs(n-c), c-n+10);
      else
        if (c > n)
          f[n] += min(abs(n-c), n-c+10);
  }
  minim = 1000000000; fo << maxim << '\n';
  for (i = 0; i <= 9; i++)
    if (f[i] < minim)
      minim = f[i];
  fo << minim << '\n';
  for (i = 0; i <= 9; i++)
    if (f[i] == minim)
      break;
  fo << i << '\n';
  for (i = 0; i <= 9; i++)
    if (f[i] == minim)
      cont++;
  fo << cont << '\n';
  return 0;
}
