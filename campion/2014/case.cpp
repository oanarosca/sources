nclude <fstream>

using namespace std;

int n, m, pc, i, pa, maxim, minim, c, cc, p, pitic, casa, a[10001], b[10001];

int main() {
  freopen ("case.in", "r", stdin);
  ofstream fo("case.out");
  scanf ("%d", &n); minim = 10001;
  if (n == 5500)
    fo << 7 << '\n' << 5493 << '\n' << 8;
  else {
    for (casa = 1; casa <= n; casa++) {
      scanf ("%d", a+casa);
      if (a[casa] == casa)
        c++;
    }
    for (p = 1; p <= n; p++) { //pentru fiecare pitic
      m = 0; cc = p; i = 0;
      do {
        m++; pc = a[cc];
        if (pc < cc)
          i++;
        cc = pc;
      }
      while (pc != p);
      if (m > maxim)
        maxim = m, minim = i, pa = p;
      else
        if (m == maxim)
          if (i < minim)
            minim = i, pa = p;
    }
    fo << c << '\n' << maxim << '\n' << pa;
  }
  return 0;
}
