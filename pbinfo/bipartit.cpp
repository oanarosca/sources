#include <fstream>

using namespace std;

struct muchie {
  int x, y;
}a[101];

int n, m, i, k, x, f[101];

int main () {
  ifstream fi("bipartit.in");
  ofstream fo("bipartit.out");
  fi >> n >> m;
  for (i = 1; i <= m; i++)
    fi >> a[i].x >> a[i].y;
  fi >> k;
  for (i = 1; i <= k; i++)
    fi >> x, f[x]++;
  for (i = 1; i <= m; i++)
    if (!(f[a[i].y] and not f[a[i].x] or f[a[i].x] and not f[a[i].y])) {
      fo << "NU"; return 0;
    }
  fo << "DA";
  return 0;
}
