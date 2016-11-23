#include <fstream>

using namespace std;

int n, v1, v2, m[102][102], l, c, maxim;

int main () {
  ifstream fi("gradmax.in");
  ofstream fo("gradmax.out");
  fi >> n;
  while (fi >> v1 >> v2) {
    if (not m[v1][v2] and not m[v2][v1])
      m[v1][0]++, m[v2][0]++, maxim = max(maxim, max(m[v1][0], m[v2][0]));
    m[v1][v2] = 1, m[v2][v1] = 1;
  }
  int nr = 0;
  for (l = 1; l <= n; l++)
    if (maxim == m[l][0]) nr++;
  fo << nr << ' ';
  for (l = 1; l <= n; l++)
    if (maxim == m[l][0])
      fo << l << ' ';
  return 0;
}
