nclude <fstream>

using namespace std;

int i, n, gp, pp, v, g, a[10001], j;

int main () {
  freopen("barbie.in", "r", stdin);
  ofstream fo("barbie.out");
  scanf("%d%d", &gp, &pp); pp -= gp;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &v, &g);
    for (j = 0; j <= pp; j++)
      if ((j % g == 0) and (a[j] == 0 or a[j] > v*j/g))
        a[j] = v*j/g; // j - greutatea, a[j] - valoarea
      else
        if ((a[j] != 0) and (a[j+g] == 0 or a[j+g] > a[j]+v) and j+g <= pp)
          a[j+g] = a[j]+v;
  }
  fo << a[pp];
  return 0;
}
