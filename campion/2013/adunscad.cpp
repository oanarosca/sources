nclude <fstream>
#include <iostream>

using namespace std;

int i, a[21], n, m, v[21], j, s;
bool gasit;

ofstream fo("adunscad.out");

void suma() {
  int s, j;

  s = 0;
  for (j = 1; j <= m; j++)
    if (a[j] == 0)
      s -= v[j];
    else
      s += v[j];
  if (s == n) {
    gasit = true;
    if (a[1] == 0)
      fo << '-';
    fo << v[1];
    for (j = 2; j <= m; j++) {
      if (a[j] == 0)
        fo << '-';
      else
        fo << '+';
      fo << v[j];
    }
  }
}

int main () {
  ifstream fi("adunscad.in");
  fi >> n >> m;
  for (i = 1; i <= m; i++)
    fi >> v[i];
  i = m;
  suma();
  do {
    if (a[i] == 1)
      a[i] = 0;
    else {
      a[i] = 1;
      i = m+1;
      //for (j = 1; j <= m; j++)
        //cout << a[j];
      //cout << '\n';
      suma();
    }
    i--;
  } while ((i >= 1) and (not gasit));
  if (not gasit)
    fo << 0 << '\n';
  return 0;
}
