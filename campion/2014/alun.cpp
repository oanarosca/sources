nclude <fstream>

using namespace std;

int n1, n2, x, k, y, i, a;
bool tura1;

int main () {
  ifstream fi("alun.in");
  ofstream fo("alun.out");
  fi >> n1 >> n2 >> x >> k >> y; tura1 = true;
  for (i = 1; i <= x; i++) {
    if (i % 2 == 0) {
      if (tura1)
        a += n1, tura1 = false;
      else
        a += n2, tura1 = true;
    }
    if (i % k == 0)
      a--;
  }
  fo << a << '\n'; a = 0; tura1 = true;
  for (i = 1; a < y; i++)
    if (i % 2 == 0) {
      if (tura1)
        a += n1, tura1 = false;
      else
        a += n2, tura1 = true;
    }
  fo << i-1;
  return 0;
}
