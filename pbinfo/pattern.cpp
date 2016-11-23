#include <iostream>
#include <fstream>

using namespace std;

int i, n, p, l, c, m[1100][1100];

void rec (int l1, int c1, int l2, int c2) {
  int mijl, mijc;

  if (l1 != l2) {
    mijl = (l1+l2)/2; mijc = (c1+c2)/2;
    for (l = l1; l <= mijl; l++)
      for (c = c1; c <= mijc; c++)
        m[l][c] = 1;
    rec (l1, mijc+1, mijl, c2);
    rec (mijl+1, c1, l2, mijc);
    rec (mijl+1, mijc+1, l2, c2);
  }
}

int main () {
  //ifstream fi("pattern.in");
  //ofstream fo("pattern.out");
  cin >> n; p = 1;
  for (i = 1; i <= n; i++)
    p *= 2;
  rec (1, 1, p, p);
  for (l = 1; l <= p; l++) {
    for (c = 1; c <= p; c++)
      cout << m[l][c] << ' ';
    cout << '\n';
  }
  return 0;
}
