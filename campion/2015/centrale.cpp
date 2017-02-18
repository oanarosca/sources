nclude <fstream>

using namespace std;

int n, i, x, centrale;

int cifre (int x) {
  int c = 0, cx = 0, u = 0, i = 0;

  x /= 10;
  while (x >= 10)
    cx *= 10, cx += x % 10, x /= 10, c++;
  u = cx % 10;
  for (i = 1; i <= c-1; i++) {
    if (cx / 10 % 10 != u)
      break;
    cx /= 10;
  }
  if (i == c)
    return 1;
  return 0;
}

int main () {
  ifstream fi("centrale.in");
  ofstream fo("centrale.out");
  fi >> n;
  for (i = 1; i <= n; i++)
    fi>> x, centrale += cifre(x);
  fo << centrale;
  return 0;
}
