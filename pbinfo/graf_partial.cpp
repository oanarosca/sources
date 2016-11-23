#include <fstream>

using namespace std;

int n, x, y, muchii, m[101][101];

int main () {
  ifstream fi("graf_partial.in");
  ofstream fo("graf_partial.out");
  fi >> n;
  while (fi >> x >> y)
    if (!m[x][y])
      m[x][y] = m[y][x] = 1, muchii++;
  for (int l = 1; l <= n; l++)
    for (int c = 1; c <= n; c++)
      if (m[l][c] and l % 2 == c % 2)
        muchii--, m[l][c] = m[c][l] = 0;
  fo << muchii;
  return 0;
}
