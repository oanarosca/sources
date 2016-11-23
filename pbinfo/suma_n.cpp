#include <iostream>
#include <fstream>

using namespace std;

int i, n, a[1001], s1, s2;

int suma (int s, int d) {
  int m, s1, s2;

  m = (s+d)/2;
  if (s == d)
    return a[s];
  else {
    s1 = suma(s, m);
    s2 = suma(m+1, d);
    return s1+s2;
  }
}

int main () {
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> a[i];
  cout << suma(1, n);
}
