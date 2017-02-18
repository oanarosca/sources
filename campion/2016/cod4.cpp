nclude <fstream>

using namespace std;

int n, m, i, a[101], b[101], alesul, f[205][11], j, k, maxim, comune, cif, nr;

void frecv (int x) {
  k++;
  while (x)
    f[k][x % 10]++, x /= 10, cif++;
}

void comp (int l1, int l2) {
  for (int i = 0; i <= 9; i++)
    if (f[l1][i] > 0 and f[l2][i] > 0)
      comune += min(f[l1][i], f[l2][i]);
}

void scoate () {
  for (int j = 0; j <= 9; j++)
    f[i][j] -= f[alesul][j];
}

void fanr () {
  nr = 0;
  for (int k = 9; k >= 0; k--)
    for (int j = 1; j <= f[i][k]; j++)
      nr *= 10, nr += k;
  if (nr < 12345) nr += 12345;
}

int main () {
  ifstream fi("cod4.in");
  ofstream fo("cod4.out");
  fi >> n >> m;
  for (i = 1; i <= n; i++)
    fi >> a[i], cif = 0, frecv(a[i]), f[k][10] = cif;
  for (i = 1; i <= m; i++)
    fi >> b[i], cif = 0, frecv(b[i]), f[k][10] = cif;
  for (i = 1; i <= n; i++) {
    maxim = 0;
    for (j = n+1; j <= n+m; j++) {
      comune = 0, comp(i, j);
      if (comune > maxim) maxim = comune, alesul = j;
    }
    if (f[i][10] % 2 == 0 and maxim >= f[i][10]/2 or f[i][10] % 2 == 1 and maxim >= f[i][10]/2+1)
      scoate(), fanr(), fo << nr << ' ';
  }
  return 0;
}
