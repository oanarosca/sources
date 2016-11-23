#include <fstream>

using namespace std;

int n, muchii, i, x, y, ok, j, f[101], m[101][101], l, nrv;

int main () {
  ifstream fi("veriflant.in");
  ofstream fo("veriflant.out");
  fi >> n >> muchii;
  for (i = 1; i <= muchii; i++)
    fi >> x >> y, m[x][y] = 1, m[y][x] = 1;
  fi >> l;
  for (i = 1; i <= l; i++) {
    fi >> nrv; ok = 1;
    for (j = 1; j <= n; j++) f[j] = 0;
    fi >> x; f[x]++;
    for (j = 1; j <= nrv-1; j++) {
      fi >> y; f[y]++;
      if (!m[x][y]) {
        ok = 0; //break;
      }
      x = y;
    }
    if (!ok) fo << "NU\n";
    else {
      for (j = 1; j <= n; j++)
        if (f[j] > 1) {
          fo << "NEELEMENTAR\n"; break;
        }
      if (j == n+1)
        fo << "ELEMENTAR\n";
    }
  }
  return 0;
}
