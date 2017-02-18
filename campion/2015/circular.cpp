nclude <fstream>

using namespace std;

int i, n;
string s1, s2;
char c;

int main () {
  ifstream fi("circular.in");
  ofstream fo("circular.out");
  fi >> n; fi >> s1 >> s2;
  if (s1 == s2) {
    fo << 0; return 0;
  }
  for (i = 1; i <= n-1; i++) { // daca nu se obtine din n-1 permutari, nu se poate obtine
    c = s1[0]; s1.erase(0, 1);
    s1 += c;
    if (s1 == s2) {
      fo << i; return 0;
    }
  }
  fo << -1;
  return 0;
}
