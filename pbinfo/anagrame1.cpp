#include <fstream>
#include <algorithm>

using namespace std;

string s;
char c[10], a[10];
int i, n;

ifstream fi("anagrame1.in");
ofstream fo("anagrame1.out");

bool valid (int i) {
  for (int j = 1; j <= i-1; j++)
    if (a[j] == a[i])
      return false;
  return true;
}

void bt (int i) {
  for (int val = 1; val <= n; val++) {
    a[i] = c[val];
    if (valid(i))
      if (i == n) {
        for (int j = 1; j <= n; j++) fo << a[j];
        fo << '\n';
      }
      else bt(i+1);
  }
}

int main () {
  fi >> s; n = s.length();
  for (i = 0; i <= n-1; i++)
    c[i+1] = s[i];
  sort(c+1, c+n+1);
  bt(1);
  return 0;
}
