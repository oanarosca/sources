nclude <fstream>

using namespace std;

int n, i, maxim, f[101], a[90001];

int main () {
  freopen ("cod5.in", "r", stdin);
  ofstream fo("cod5.out");
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]), f[a[i]]++;
    if (a[i] > maxim)
      maxim = a[i];
  }
  for (i = 0; i <= maxim; i++)
    if (f[i] % 2 == 1)
      fo << i;
  return 0;
}
