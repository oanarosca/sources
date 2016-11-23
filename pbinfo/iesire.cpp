#include <fstream>

using namespace std;

ifstream fi("iesire.in");
ofstream fo("iesire.out");

int n, camere, l, c, m[102][102], a[102][102], i;
bool ok;

void reset () {
  for (int l = 1; l <= n; l++)
    for (int c = 1; c <= n; c++)
      a[l][c] = 0;
}

void fill (int l, int c) {
  if (not m[l][c]) {
    if (l == 1 or c == 1 or l == n or c == n)
      fo << "da\n", ok = true, reset();
    else
      if (not a[l][c]) {
        a[l][c] = 1;
        fill (l-1, c); if (ok) return;
        fill (l, c+1); if (ok) return;
        fill (l+1, c); if (ok) return;
        fill (l, c-1); if (ok) return;
      }
  }
}

int main () {
  fi >> n >> camere;
  for (l = 1; l <= n; l++)
    for (c = 1; c <= n; c++)
      fi >> m[l][c];
  for (i = 1; i <= camere; i++) {
    fi >> l >> c, ok = false; fill (l, c);
    if (not ok) fo << "nu\n";
  }
  return 0;
}
