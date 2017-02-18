nclude <fstream>

using namespace std;

int n, i, p[100001], bp, a;

int main () {
  freopen("carti1.in", "r", stdin);
  ofstream fo("carti1.out");
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a); p[a] = i;
  }
  for (i = 1; i <= n-1; i++)
    if (p[i] > p[i+1])
      bp++;
  fo << bp;
  return 0;
}
