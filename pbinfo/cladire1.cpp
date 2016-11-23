#include <fstream>

using namespace std;

int lin, col, m[1001][1001], k;

int main () {
  ifstream fi("cladire1.in");
  ofstream fo("cladire1.out");
  fi >> lin >> col;
  for (int l = 1; l <= lin; l++)
    for (int c = 1; c <= col; c++)
      m[l][c] = -1;
  m[1][0] = 1; fi >> k; int x, y;
  for (int i = 1; i <= k; i++)
    fi >> x >> y, m[x][y] = 0;
  for (int l = 1; l <= lin; l++)
    for (int c = 1; c <= col; c++)
      if (m[l][c] != 0)
        m[l][c] = (m[l-1][c]+m[l][c-1])%9901;
  fo << m[lin][col];
  return 0;
}
