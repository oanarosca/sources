nclude <fstream>

using namespace std;

int n, i, p, maxim, ap, v, a[10], j;
long long o, c, b, cuburi;

int main () {
  ifstream fi("cladiri2.in");
  ofstream fo("cladiri2.out");
  fi >> n;
  for (i = 1; i <= n; i++) {
    fi >> b; o = 0; v = 0;
    for (j = 1; j <= 9; j++)
      a[j] = 0;
    c = b; j = 0;
    while (c) {
      j++;
      if (c % 10 > maxim)
        maxim = c % 10, ap = 1, v = 1;
      else
        if ((c % 10 == maxim) and (v == 0))
          ap++, v = 1;
      o = o*10+c % 10; a[j] = c % 10;
      c /= 10;
    }
    if (b == o)
      p++;
    else
      for (c = 1; c <= j/2; c++)
        if (a[c] < a[j-c+1])
          cuburi += a[j-c+1]-a[c];
        else
          if (a[c] > a[j-c+1])
            cuburi += a[c]-a[j-c+1];
  }
  fo << maxim << ' ' << ap << '\n' << p << '\n' << cuburi;
  return 0;
}
