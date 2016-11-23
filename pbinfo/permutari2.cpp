#include <fstream>
#include <algorithm>

using namespace std;

int n, i, a[100], b[100];

ifstream fi("permutari2.in");
ofstream fo("permutari2.out");

void scrie () {
  for (int i = 1; i <= n; i++)
    fo << b[i] << ' ';
  fo << '\n';
}

bool valid (int i) {
  for (int j = 1; j <= i-1; j++)
    if (b[j] == b[i]) return false;
  return true;
}

void bt (int i) {
  for (int j = 1; j <= n; j++) {
    b[i] = a[j];
    if (valid(i))
      if (i == n) scrie();
      else bt(i+1);
  }
}

int main () {
  fi >> n;
  for (i = 1; i <= n; i++)
    fi >> a[i];
  sort(a+1, a+n+1);
  bt(1);
  return 0;
}
