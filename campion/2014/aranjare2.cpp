nclude <fstream>

using namespace std;

struct sticluta {
  int v; int p; // valoarea si pozitia
};

sticluta a[100001];
int i, n;
bool ordonat;

int main () {
  freopen ("aranjare2.in", "r", stdin);
  freopen ("aranjare2.out", "w", stdout);
  scanf("%d%d", &n, &a[1].v); a[1].p = 1;
  for (i = 2; i <= n; i++)
    scanf("%d", &a[i].v), a[i].p = a[i-1].p+2;
  scanf("%d", &a[n+1].v); a[n+1].p = 2;
  for (i = n+2; i <= 2*n; i++)
    scanf("%d", &a[i].v), a[i].p = a[i-1].p+2;
  do {
    ordonat = true;
    for (i = 1; i <= 2*n; i++)
      if (i != a[i].p) {
        printf("%d %d\n", i, a[i].p), swap(a[i], a[a[i].p]), ordonat = false; break;
      }
  } while (not ordonat);
  return 0;
}
