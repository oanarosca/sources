#include <fstream>

using namespace std;

int n, x, y, maxim, m[101][101], elim;

int main () {
  ifstream fi("graf_partial_2.in");
  ofstream fo("graf_partial_2.out");
  fi >> n;
  while (fi >> x >> y)
    if (!m[x][y])
      m[x][0]++, m[y][0]++, m[x][y] = m[y][x] = 1, maxim = max(maxim, max(m[x][0], m[y][0]));
  for (int l = 1; l <= n; l++)
    for (int c = 1; c <= n; c++)
      if (m[l][0] == maxim and m[l][c])
        m[l][c] = m[c][l] = 0, elim++;
  fo << elim << '\n';
  for (int l = 1; l <= n; l++) {
    for (int c = 1; c <= n; c++)
      fo << m[l][c] << ' ';
    fo << '\n';
  }
  return 0;
}
