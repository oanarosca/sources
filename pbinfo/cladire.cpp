#include <fstream>

using namespace std;

int lin, col, m[1001][1001];

int main () {
  ifstream fi("cladire.in");
  ofstream fo("cladire.out");
  fi >> lin >> col; m[1][0] = 1;
  for (int l = 1; l <= lin; l++)
    for (int c = 1; c <= col; c++)
      m[l][c] = (m[l-1][c]+m[l][c-1])%9901;
  fo << m[lin][col];
  return 0;
}
