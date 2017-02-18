nclude <fstream>
#include <algorithm>

using namespace std;

int s, n, i, a[10001], b[10001], p;

int cmp (int x, int y) {
  return  x > y;
}

int main () {
  ifstream fi("bete1.in");
  ofstream fo("bete1.out");
  fi >> n;
  for (i = 1; i <= n; i++) {
    fi >> a[i]; s += a[i];
  }
  for (i = 1; i <= n; i++) {
    fi >> b[i]; s += b[i];
  }
  fo << s/n << '\n';
  sort (a+1, a+n+1, cmp);
  sort (b+1, b+n+1, cmp);
  fo << a[1]+b[1] << '\n';
  for (i = 1; i <= n; i++)
    if (a[i]+b[i] == a[1]+b[1])
      p++;
  fo << p;
  return 0;
}
