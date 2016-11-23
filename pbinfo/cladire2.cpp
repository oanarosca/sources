#include <fstream>

using namespace std;

struct camera {
  int l, c;
}a[1001];

int lin, col, m[201][201], l, k, c;

int main () {
  ifstream fi("cladire2.in");
  ofstream fo("cladire2.out");
  fi >> lin >> col;
  for (l = 1; l <= lin; l++)
    for (c = 1; c <= col; c++)
      fi >> m[l][c];
  for (l = 1; l <= lin; l++)
    for (c = 1; c <= col; c++)
      m[l][c] += max(m[l-1][c], m[l][c-1]);
  fo << m[lin][col] << '\n'; l = lin, c = col;
  while (l != 1 or c != 1) {
    a[++k].l = l, a[k].c = c;
    if (m[l-1][c] > m[l][c-1])
      l = l-1;
    else c = c-1;
  }
  fo << "1 1\n";
  while (k)
    fo << a[k].l << ' ' << a[k].c << '\n', k--;
  return 0;
}
