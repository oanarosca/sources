#include <fstream>

using namespace std;

int n, a[101], k;

ifstream fi("permutari1.in");
ofstream fo("permutari1.out");

void afis () {
  for (int i = 1; i <= n; i++)
    fo << a[i] << ' ';
  fo << '\n';
}

bool valid (int i) {
  for (int j = 1; j < i; j++)
    if (a[j] == a[i]) return false;
  return true;
}

void bt (int i) {
  for (int val = n; val >= 1; val--) {
    a[i] = val;
    if (valid(i))
      if (i == n) afis();
      else bt(i+1);
  }
}

int main () {
  fi >> n;
  bt(1);
  return 0;
}
