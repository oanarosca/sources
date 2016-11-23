#include <fstream>

using namespace std;

int lin, col, l, c, m[102][102], a[102][102], crocodili, elefanti, t1, t2;

void fill (int l, int c, char ch) {
  if (1 <= l and l <= lin and 1 <= c and c <= col)
    if (not m[l][c] and not a[l][c]) {
      a[l][c] = ch;
      if (ch == 'C') t1++, ch = 'E';
      else t2++, ch = 'C';
      fill (l-1, c, ch);
      fill (l, c+1, ch);
      fill (l+1, c, ch);
      fill (l, c-1, ch);
    }
}

int main () {
  ifstream fi("croco1.in");
  ofstream fo("croco1.out");
  fi >> lin >> col;
  for (l = 1; l <= lin; l++)
    for (c = 1; c <= col; c++) {
      fi >> m[l][c];
      if (m[l][c])
        a[l][c] = 'A';
    }
  for (l = 1; l <= lin; l++)
    for (c = 1; c <= col; c++)
      if (not m[l][c] and not a[l][c]) {
        t1 = t2 = 0;
        fill (l, c, 'C');
        crocodili += max(t1, t2); elefanti += min(t1, t2);
      }
  fo << crocodili << ' ' << elefanti;
  return 0;
}
