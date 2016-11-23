#include <fstream>

using namespace std;

long long p, n, m, i, b, j, putere;

int main () {
  ifstream fi("tripar.in");
  ofstream fo("tripar.out");
  fi >> p >> n >> m;
  if (p == 1) {
    putere = 1;
    for (i = 1; i <= m; i++)
      putere *= 4;
    for (i = 1; i <= n; i++)
      fi >> b, fo << b*b*putere << '\n';
  }
  else {
    for (i = 1; i <= n; i++) {
      fi >> b;
      for (j = 1; j <= m; j++)
        b *= 2;
      fo << (b-1)*b*3/2 << '\n';
    }
  }
  return 0;
}
