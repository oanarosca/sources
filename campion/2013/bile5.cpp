nclude <cstdio>

using namespace std;

int n, i;

int main () {
  #ifndef ONLINE_JUDGE
      freopen("bile5.in", "r", stdin);
      freopen("bile5.out", "w", stdout);
  #endif
  scanf("%d", &n);
  if (n % 2 == 1) {
    for (i = 1; i <= (n-1)/2; i++) {
      printf("%d %d\n", n+1+n/2-i+1, 2*n+1-n/2+i-1); //fo << n+1+n/2-i+1 << ' ' << 2*n+1-n/2+i-1 << '\n';
      printf("%d %d\n", 1+n/2-i, n-n/2+i); //fo << 1+n/2-i << ' ' << n-n/2+i << '\n';
    }
    printf("%d %d\n%d", n+1, 2*n+1, 1+n/2); //fo << n+1 << ' ' << 2*n+1 << '\n' << 1+n/2;
  }
  else {
    for (i = 1; i <= n/2; i++) {
      printf("%d %d\n", n/2-i+1, n/2+i); //fo << n/2-i+1 << ' ' << n/2+i << '\n';
      printf("%d %d\n", n+1+n/2-i, 2*n+1-n/2+i); //fo << n+1+n/2-i << ' ' << 2*n+1-n/2+i << '\n';
    }
    printf("%d\n", n+1+n/2); //fo << n+1+n/2;
  }
  return 0;
}
