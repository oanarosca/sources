nclude <fstream>

using namespace std;

int n, i, l, c, lmax, ls;
string s;
char m[200][200];
int main () {
  ifstream fi("alfabetar.in");
  ofstream fo("alfabetar.out");
  fi >> n;
  for (i = 1; i <= n; i++) {
    fi >> s;
    ls = s.length();
    if (ls > lmax)
      lmax = ls;
    for (l = 0; l <= ls-1; l++)
      m[l][i] = s[l];
  }
  for (l = lmax-1; l >= 0; l--) {
    for (c = 1; c <= n; c++)
      if (m[l][c] == 0)
        fo << ' ';
      else
        fo << m[l][c];
    fo << '\n';
  }
  return 0;
}
