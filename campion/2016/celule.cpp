nclude <fstream>
#include <cmath>

using namespace std;

int n, m, maxim, i, sol, r;

int main () {
  ifstream fi("celule.in");
  ofstream fo("celule.out");
  fi >> n >> m; maxim = max(n, m); r = sqrt(maxim);
  for (i = 2; i <= r; i++) {
    while (n % i == 0 and m % i == 0)
      n /= i, m /= i;
    while (n % i == 0)
      n /= i, sol++;
    while (m % i == 0)
      m /= i, sol++;
  }
  if (n > 1) sol++;
  if (m > 1) sol++;
  fo << sol;
  return 0;
}
