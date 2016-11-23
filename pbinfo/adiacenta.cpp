#include <fstream>

using namespace std;

int n, nr, i, m[102][102], l, c;

int main () {
  ifstream fi("adiacenta.in");
  ofstream fo("adiacenta.out");
  fi >> n >> nr;
  for (i = 1; i <= nr; i++)
    fi >> l >> c, m[l][c] = 1, m[c][l] = 1;
  for (int l = 1; l <= n; l++) {
    for (int c = 1; c <= n; c++)
      fo << m[l][c] << ' ';
    fo << '\n';
  }
  return 0;
}
