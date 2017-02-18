nclude <fstream>

using namespace std;

int x, cmax, c, z, nrmax, i, nc, a, maxpar, n, j, nr,k;

int main() {
  ifstream fi("alice.in");
  ofstream fo("alice.out");
  fi >> n >> k;
  for(j = 1; j <= n; j++) {
    fi >> a; z = x = a;
    if (a % 2 == 0 && maxpar < a)
      maxpar = a;
    do {
      a = z; z = x; cmax = 0; nc = 0;
      while (x) {
        c = x % 10; x = x/10; nc++;
        if (c > cmax)
          cmax = c;
      }
      nrmax = 0;
      for(i = 1; i <= nc; i++)
        nrmax = nrmax*10+cmax;
      x = nrmax-z;
    } while (x > 9 && x != z && x != a);
    if (x == k)
      nr++;
  }
  fo << maxpar << '\n' << nr;
  return 0;
}
