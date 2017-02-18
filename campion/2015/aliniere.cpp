nclude <fstream>

using namespace std;

int i, p1, p2, n, sol;

int main () {
  ifstream fi("aliniere.in");
  ofstream fo("aliniere.out");
  fi >> n; p1 = 1; p2 = 2;
  if (n == 1) {
    fo << 1; return 0;
  }
  if (n == 2) {
    fo << 2; return 0;
  }
  for (i = 3; i <= n; i++)
    sol = (p1+p2) % 9973, p1 = p2, p2 = sol;
  fo << sol;
  return 0;
}
