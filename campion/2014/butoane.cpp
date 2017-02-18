nclude <fstream>
#include <cstdlib>

using namespace std;

int n, i, minim, a[1001], b[1001], m;

int main () {
  ifstream fi("butoane.in");
  ofstream fo("butoane.out");
  fi >> n;
  for (i = 1; i <= n; i++)
    fi >> b[i], m += b[i];
  m /= n;
  a[2] = m-(b[1]-a[1]);
  for (i = 3; i <= n-1; i++)
    a[i] = m-(b[i-1]+a[i-2]-2*a[i-1]);
  a[n] = b[n]+a[n-1]-m;
  for (i = 1; i <= n; i++)
    if (a[i] < minim)
      minim = a[i];
  if (minim == 0)
    for (i = 1; i <= n; i++)
      fo << a[i] << '\n';
  else
    for (i = 1; i <= n; i++)
      fo << a[i]+abs(minim) << '\n';
  return 0;
}
