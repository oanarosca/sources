#include <fstream>
#include <algorithm>

using namespace std;

int n, a[101], b[101];

ifstream fi("sirpie.in");
ofstream fo("sirpie.out");

void scrie () {
  for (int i = 1; i <= n; i++)
    fo << b[i] << ' ';
  fo << '\n';
}

bool valid (int j) {
  if (j == 1)
    return true;
  for (int i = 1; i <= j-1; i++)
    if (b[i] == b[j]) return false;
  int d = b[j-1], i = b[j];
  do {
    int r = d % i;
    d = i, i = r;
  } while (i);
  if (d == 1) return true;
  return false;
}

void bt (int i) {
  for (int val = 1; val <= n; val++) {
    b[i] = a[val];
    if (valid(i))
      if (i == n) scrie();
      else bt(i+1);
  }
}

int main () {
  fi >> n;
  for (int i = 1; i <= n; i++)
    fi >> a[i];
  sort(a+1, a+n+1);
  bt(1);
  return 0;
}
