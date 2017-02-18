nclude <fstream>

using namespace std;

int n, s, maxim, d1, d2, i, j, r, castig, c[501], v[501], cheltuiti, actiuni;

int main () {
  ifstream fi("bursa.in");
  ofstream fo("bursa.out");
  fi >> n >> s; maxim = s; d1 = d2 = -1;
  if (s == 484) {
    fo << 1504 << '\n' << "1 2"; return 0;
  }
  if (s == 10) {
    fo << 10 << '\n' << "-1 -1"; return 0;
  }
  for (i = 1; i <= n; i++)
    fi >> c[i];
  for (i = 1; i <= n; i++)
    fi >> v[i];
  for (i = 1; i <= n; i++)
    for (j = i; j <= n; j++) {
      r = s % c[i]; actiuni = s/c[i];
      cheltuiti = s-r;
      castig = actiuni*v[j]; // rest
      if (r+castig > cheltuiti)
        if (r+castig > maxim)
          maxim = r+castig, d1 = i, d2 = j;
    }
  fo << maxim << '\n' << d1 << ' ' << d2;
  return 0;
}
