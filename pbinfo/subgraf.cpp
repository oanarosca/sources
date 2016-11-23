#include <fstream>
#include <cmath>

using namespace std;

int n, x, y, muchii, m[102][102];

bool prim (int x) {
  for (int i = 2; i <= sqrt(x); i++)
    if (x % i == 0) return false;
  return true;
}

int main () {
  ifstream fi("subgraf.in");
  ofstream fo("subgraf.out");
  fi >> n;
  while (fi >> x >> y) {
    if (!m[x][y]) muchii++;
    if (!m[y][x]) muchii++;
    m[x][y] = m[y][x] = 1;
  }
  for (int i = 2; i <= n; i++)
    if (prim(i))
      for (int j = 1; j <= n; j++) {
        if (m[j][i]) m[j][i] = 0, muchii--;
        if (m[i][j]) m[i][j] = 0, muchii--;
      }
  fo << muchii/2;
  return 0;
}
