#include <fstream>

using namespace std;

int n, x, y, m[101][101], elim, minim = 2e9, maxim;

int main () {
  ifstream fi("graf_partial_1.in");
  ofstream fo("graf_partial_1.out");
  fi >> n;
  while (fi >> x >> y)
    if (!m[x][y])
      m[x][y] = m[y][x] = 1, m[x][0]++, m[y][0]++;
  for (int i = 1; i <= n; i++)
    maxim = max(maxim, m[i][0]), minim = min(minim, m[i][0]);
  for (int l = 1; l <= n; l++)
    for (int c = 1; c <= n; c++)
      if (m[l][c] and m[l][0] == maxim and m[c][0] == minim)
        elim++, m[l][c] = m[c][l] = 0;
  fo << elim << '\n';
  for (int l = 1; l <= n; l++) {
    for (int c = 1; c <= n; c++)
      fo << m[l][c] << ' ';
    fo << '\n';
  }
  return 0;
}
