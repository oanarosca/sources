#include <fstream>

using namespace std;

int g, i, n, m, x, l, c;

int main () {
  ifstream fi("graf_complet.in");
  ofstream fo("graf_complet.out");
  fi >> g;
  for (i = 1; i <= g; i++) {
    fi >> n; m = 0;
    for (l = 1; l <= n; l++)
      for (c = 1; c <= n; c++)
        fi >> x, x == 1 ? m++ : m;
    if (m == n*(n-1))
      fo << "DA\n";
    else fo << "NU\n";
  }
  return 0;
}
