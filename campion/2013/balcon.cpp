nclude <fstream>
#include <algorithm>

using namespace std;

int i, n, a[2501], m[51][51], l, c, j, nf;

int main () {
  ifstream fi("balcon.in");
  ofstream fo("balcon.out");
  fi >> n;
  for (i = 1; i <= n*n; i++)
    fi >> a[i];
  sort (a+1, a+n*n+1); a[j] = -1; nf = n*n;
  for (i = 1; nf > 0; i++) {
    for (c = i; c <= n-i+1; c++) {
      j++; m[i][c] = a[j]; nf--;
    }
    for (l = i+1; l <= n-i+1; l++) {
      j++; m[l][n-i+1] = a[j]; nf--;
    }
    for (c = n-i; c >= i; c--) {
      j++; m[n-i+1][c] = a[j]; nf--;
    }
    for (l = n-i; l >= i+1; l--) {
      j++; m[l][i] = a[j]; nf--;
    }
  }
  for (l = 1; l <= n; l++) {
    for (c = 1; c <= n; c++)
      fo << m[l][c] << ' ';
    fo << '\n';
  }
  return 0;
}
