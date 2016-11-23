#include <fstream>

using namespace std;

int lin, col, l, c, m[102][102], a[102][102];

void fill (int l, int c, char ch) {
  if (m[l][c] and not a[l][c]) {
    a[l][c] = ch;
    if (ch == 'C') ch = 'E';
    else ch = 'C';
    fill (l-1, c, ch);
    fill (l, c+1, ch);
    fill (l+1, c, ch);
    fill (l, c-1, ch);
  }
}

int main () {
  ifstream fi("croco.in");
  ofstream fo("croco.out");
  fi >> lin >> col;
  for (l = 1; l <= lin; l++)
    for (c = 1; c <= col; c++) {
      fi >> m[l][c];
      if (not m[l][c])
        a[l][c] = 'A';
    }
  for (l = 1; l <= lin; l++)
    for (c = 1; c <= col; c++)
      if (m[l][c] and not a[l][c])
        fill (l, c, 'C');
  for (l = 1; l <= lin; l++) {
    for (c = 1; c <= col; c++)
      fo << (char)a[l][c] << ' ';
    fo << '\n';
  }
  return 0;
}
