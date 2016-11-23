#include <fstream>
#include <iostream>

using namespace std;

long long n, nfact;

long long fact (long long k) {
  long long i, p = 1;

  for (i = 1; i <= k; i++)
    p *= i;
  return p;
}

int main () {
  ifstream fi("triunghiul.in");
  ofstream fo("triunghiul.out");
  fi >> n; nfact = fact(n);
  for (long long i = 0; i <= n; i++)
    fo << nfact/(fact(n-i)*fact(i)) << ' ';
  return 0;
}
