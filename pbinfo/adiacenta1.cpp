#include <fstream>

using namespace std;

int l, c, m[1001][1001], maxim;

int main () {
  ifstream fi("adiacenta1.in");
  ofstream fo("adiacenta1.out");
  while (fi >> l >> c) {
    m[l][c] = 1; m[c][l] = 1;
    maxim = max(maxim, max(l, c));
  }
  for (l = 1; l <= maxim; l++) {
    for (c = 1; c <= maxim; c++)
      fo << m[l][c] << ' ';
    fo << '\n';
  }
  return 0;
}
