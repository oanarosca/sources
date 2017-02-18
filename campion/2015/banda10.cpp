nclude <fstream>

using namespace std;

int i, n, a[1001], b[1001], s[1002], sa[1002];
char c;

void p2 (int putere) {
  int i, j, t = 0;

  a[0] = 1; a[1] = 2;
  for (i = 1; i <= putere; i++) { // adun vectorul a cu vectorul a, ca si cum l-as inmulti cu 2
    for (j = 1; j <= a[0] or t; j++, t /= 10)
      sa[j] = (t += a[j]+a[j]) % 10;
    sa[0] = j-1;
    for (j = 0; j <= sa[0]; j++)
      a[j] = sa[j];
  }
}

void suma (int a[1001], int b[1001]) {
  int t = 0, i;

  for (i = 1; i <= s[0]; i++)
    b[i] = s[i];
  b[0] = s[0];
  for (i = 1; i <= a[0] or i <= b[0] or t; i++, t /= 10)
    s[i] = (t += a[i]+b[i]) % 10;
  s[0] = i-1;
}

void REINITIALIZARE () {
  int i;

  for (i = 1; i <= a[0]; i++)
    a[i] = 0;
}

int main () {
  ifstream fi("banda10.in");
  ofstream fo("banda10.out");
  fi >> n; fi.get();
  for (i = 1; i <= n; i++) {
    fi.get(c);
    if (c == '1') {
      p2(n-i-1); // puterea lui 2
      suma(a, b);
      REINITIALIZARE();
    }
  }
  if (s[0] == 0) // numarul din fisierul de intrare era 00000000
    fo << 1;
  else
    fo << s[0];
  return 0;
}
