#include <fstream>

using namespace std;

int lin, col, cad, l, c, m[201][201], maxim, cmax, i;

void fill (int l, int c) {
  if (1 <= l and l <= lin and 1 <= c and c <= col)
    if (not m[l][c]) {
      m[l][c] = -1;
      fill (l-1, c);
      fill (l, c+1);
      fill (l+1, c);
      fill (l, c-1);
    }
    else {
      if (m[l][c] > maxim)
        maxim = m[l][c], cmax = 1;
      else if (m[l][c] == maxim)
        cmax++;
      m[l][c] = -1;
    }
}

int main () {
  ifstream fi("zana.in");
  ofstream fo("zana.out");
  fi >> lin >> col >> cad;
  for (i = 1; i <= cad; i++)
    fi >> l >> c, m[l][c]++;
  fill (1, 1);
  fo << maxim << '\n' << cmax;
  return 0;
}
