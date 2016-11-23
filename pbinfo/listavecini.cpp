#include <fstream>

using namespace std;

int n, v1, v2, m[102][102], l, c;

int main () {
  ifstream fi("listavecini.in");
  ofstream fo("listavecini.out");
  fi >> n;
  while (fi >> v1 >> v2) {
    if (not m[v1][v2] and not m[v2][v1])
      m[v1][0]++, m[v2][0]++;
    m[v1][v2] = 1, m[v2][v1] = 1;
  }
  for (l = 1; l <= n; l++) {
    fo << m[l][0] << ' ';
    for (c = 1; c <= n; c++)
      if (m[l][c])
        fo << c << ' ';
    fo << '\n';
  }
  return 0;
}
