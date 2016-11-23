#include <fstream>

using namespace std;

int lin, col, l, c, z, m[102][102], a[102][102];

void fill (int l, int c) {
  if (m[l][c] and not a[l][c]) {
    a[l][c] = 1;
    fill (l-1, c);
    fill (l, c+1);
    fill (l+1, c);
    fill (l, c-1);
  }
}

int main () {
  ifstream fi("fill.in");
  ofstream fo("fill.out");
  fi >> lin >> col;
  for (l = 1; l <= lin; l++)
    for (c = 1; c <= col; c++)
      fi >> m[l][c];
  for (l = 1; l <= lin; l++)
    for (c = 1; c <= col; c++)
      if (m[l][c] and not a[l][c])
        z++, fill (l, c);
  fo << z;
  return 0;
}
