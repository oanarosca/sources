#include <iostream>

using namespace std;

int n, i, z, a[33000];

void pune (int p) {
  int t, mij, i;
  mij = p/2+1;
  for (i = n; i >= mij; i--)
    a[i+p]=a[i];
  t = p+1;
  for(i = mij; i <= mij+p-1; i++)
    a[i] = t++;
  n = n+p;
  if (n < z)
    pune(2*p);
}

int main () {
  cin >> n; z = 1;
  for (i = 1; i <= n; i++)
    z *= 2;
  a[1] = 1, a[2] = 2;
  pune(2);
  for (i = 1; i <= z; i++)
    cout << a[i] << ' ';
  return 0;
}
