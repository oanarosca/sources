#include <fstream>

using namespace std;

struct interval {
  int inc, sf;
}b[10001];

int n, m, i, q, p, j, a[100001];

int main () {
  ifstream fi("copii.in");
  ofstream fo("copii.out");
  fi >> n;
  for (i = 1; i <= n; i++) fi >> a[i];
  fi >> m;
  for (i = 1; i <= m; i++) fi >> b[i].inc >> b[i].sf;
  fi >> q;
  for (i = 1; i <= q; i++) {
    fi >> p;
    for (j = m; j >= 1; j--) {
      if (b[j].inc <= p and p <= b[j].sf)
        p = b[j].sf-p+b[j].inc;
    }
    fo << a[p] << '\n';
  }
  return 0;
}
