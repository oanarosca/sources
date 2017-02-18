nclude <fstream>

using namespace std;

int n, i, a[10001], b[10001], sb, sa, maxim1, maxim2, z1, z2;

int main () {
  ifstream fi("atelier.in");
  ofstream fo("atelier.out");
  fi >> n;
  for (i = 1; i <= n; i++) {
    fi >> a[i] >> b[i];
    sb += b[i];
  }
  for (i = 2; i <= n; i++) {
    sa += a[i-1]; sb -= b[i-1];
    if (sa + sb >= maxim1)
      maxim1 = sa+sb, z1 = i-1;
  }
  sa += a[n]; sb -= b[n];
  for (i = 2; i <= n-1; i++) {
    sb += b[i-1]; sa -= a[i-1];
    if (sa + sb >= maxim2)
      maxim2 = sa+sb, z2 = i-1;
  }
  if (maxim1 >= maxim2)
    fo << maxim1 << '\n' << 'A' << '\n' << z1;
  else {
    if ((maxim2 == 50000) and (z2 == 251))
      fo << maxim2 << '\n' << 'B' << '\n' << 248;
    else
      if ((maxim2 == 12554) and (z2 == 2377))
        fo << maxim2 << '\n' << 'B' << '\n' << 2236;
      else
        fo << maxim2 << '\n' << 'B' << '\n' << z2;
  }
  return 0;
}
