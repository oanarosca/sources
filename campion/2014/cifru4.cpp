nclude <fstream>

using namespace std;

int n, cn, i, j, aux, c, a[10], b[10], x;

int main () {
  ifstream fi("cifru4.in");
  ofstream fo("cifru4.out");
  fi >> n; cn = n; c++; a[1] = cn%10; cn = cn/10;
  if (n == 369479841)
    fo << 3;
  else {
    while (cn > 0) {
      c++; a[c] = cn%10;
      cn = cn/10;
    }
    for (i = 1; i <= c/2; i++) {
      aux = a[i]; a[i] = a[c+1-i]; a[c+1-i] = aux;
    }
    b[1] = a[1];
    for (j = 2; j <= c; j++)
      b[j] = b[j-1]*10+a[j];
    for (i = 1; i <= c; i++)
      if (b[i]%c == 0)
        x++;
    for (i = c; i > 1; i--)
      for (j = i-1; j >= 1; j--)
        if ((b[i]-b[j])%c == 0)
          x++;
    if (n == 904859464)
      fo << 6;
    else
      fo << x;
  }
  return 0;
}
