nclude <fstream>

using namespace std;

char b[500001];
int i, n, x, c, m, p, u, s, j, c3;
int a[34] = {0, 3, 5, 9, 25, 27, 81, 125, 243, 625, 729, 2187, 3125, 6561, 15625, 19683, 59049, 78125, 177147, 390625, 531441, 1594323, 1953125, 4782969, 48828125, 9765625, 14348907, 43046721, 129140163, 244140625, 387420489, 1162261467, 1220703125};
//int b[14] = {0, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625, 1220703125};

int main () {
  freopen ("235.in", "r", stdin);
  ofstream fo("235.out");
  scanf ("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf ("%d", &x);
    p = 1; u = 34;
    do {
      m = (p+u)/2;
      if (x == a[m]) {
        c++;
        if (a[m] % 5 == 0)
          b[c] = 5;
        else
          b[c] = 3;
        break;
      }
      else
        if (x < a[m])
          u = m-1;
        else
          p = m+1;
    }
    while (p <= u);
  }
  fo << c << '\n';
  for (p = 2; p <= c; p *= 2) {
    c3 = 0;
    for (i = 1; i <= p; i++)
      if (b[i] == 3)
        c3++;
    if (c3 == p/2)
      s++;
    for (i = 2, j = i+p-1; j <= c; i++, j++) {
      if (b[i-1] == 3)
        c3--;
      if (b[j] == 3)
        c3++;
      if (c3 == p/2)
        s++;
    }
  }
  fo << s;
  return 0;
}
