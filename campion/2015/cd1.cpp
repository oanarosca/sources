nclude <fstream>

using namespace std;

int n, s, i, nrcd, c, a[301], p;

int main () {
  ifstream fi("cd1.in");
  ofstream fo("cd1.out");
  fi >> n >> s; p = 1;
  for (i = 1; i <= n; i++) {
    fi >> nrcd >> c;
    a[c] += nrcd, a[i] -= nrcd;
  }
  for (i = 1; i <= n; i++) {
    if (a[i] < 0)
      a[i] *= -1, a[i] += s / n;
    else
      a[i] = s / n-a[i];
    a[i]--; p = (p % 9901 * a[i] % 9901) % 9901;
  }
  fo << p;
  return 0;
}
