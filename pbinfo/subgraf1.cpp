#include <fstream>

using namespace std;

int n, x, y, muchii, m[102][102], minim = 2e9, a[1002], i;

int main () {
  ifstream fi("subgraf1.in");
  ofstream fo("subgraf1.out");
  fi >> n;
  while (fi >> x >> y)
    if (!m[x][y])
      m[x][y] = 1, m[y][x] = 1, muchii++, a[x]++, a[y]++;
  for (i = 1; i <= n; i++)
    minim = min(minim, a[i]);
  for (i = 1; i <= n; i++)
    if (a[i] == minim)
      for (int j = 1; j <= n; j++)
        if (m[i][j]) m[i][j] = m[j][i] = 0, muchii--;
  fo << muchii;
  return 0;
}
