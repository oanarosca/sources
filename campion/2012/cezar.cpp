nclude <fstream>

using namespace std;

string s, s2, fs;
int i, a[10], l, spatii[300], j, lfs, spatiu;

int main () {
  ifstream fi("cezar.in");
  ofstream fo("cezar.out");
  getline(fi, s);
  for (i = 0; i <= 9; i++)
    fi >> a[i];
  l = s.length();
  for (i = 0; i <= l - 1; i++) {
    if (s[i] == ' ') {
      spatii[i] = 1;
      spatiu++;
    }
    else
      fs += s[i];
  }
  for (i = 0, j = 0; i <= fs.length() - 1; i++, j = (j + 1) % 10)
    if (fs[i] - a[j] < 65)
      s2 += fs[i] - a[j] + 26;
    else
      s2 += fs[i] - a[j];
  for (i = j = 0; j <= l-spatiu-1; i++, j++)
    if (spatii[i] == 1) {
      fo << ' ' << s2[j]; i++;
    }
    else
      fo << s2[j];
  return 0;
}
