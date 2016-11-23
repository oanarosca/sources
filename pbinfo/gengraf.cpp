#include <fstream>

using namespace std;

struct muchie {
  int l, c;
}a[101];

int n, l, c, i, m[101][101], g[101], noduri;

void init () {
  for (int l = 1; l <= noduri; l++)
    for (int c = 1; c <= noduri; c++)
      m[l][c] = 0;
}

ifstream fi("gengraf.in");
ofstream fo("gengraf.out");

void afis () {
  init();
  for (int i = 1; i <= n; i++)
    m[a[i].l][a[i].c] = g[i], m[a[i].c][a[i].l] = g[i];
  for (int l = 1; l <= noduri; l++) {
    for (int c = 1; c <= noduri; c++)
      fo << m[l][c] << ' ';
    fo << '\n';
  }
  fo << '\n';
}

int main () {
  fi >> n;
  for (l = 1; l <= n-1; l++)
    for (c = l+1; c <= n; c++)
      a[++i].l = l, a[i].c = c;
  noduri = n, n = n*(n-1)/2;
  int p = 1;
  for (i = 1; i <= n; i++)
    p *= 2;
  fo << p << '\n';
  while (!g[0]) {
    afis();
    g[n]++;
    if (g[n] > 1) {
      g[n] = 0;
      i = n-1;
      while (g[i])
        g[i] = 0, i--;
      g[i] = 1;
    }
  }
  return 0;
}
