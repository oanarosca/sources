nclude <fstream>

using namespace std;

long long n, cn, a;
int i, f[10], c[10], cifre, j, cifre2, f2[10], x, c2[10], e;
bool afisat, anagramabil;

int main () {
  ifstream fi("anagramabil.in");
  ofstream fo("anagramabil.out");
  fi >> n; cn = n;
  while (cn >= 10) {
    i++;
    c[i] = cn%10;
    cn = cn/10;
  }
  i++; cifre = i;
  c[i] = cn;
  for (i = 0; i <= 9; i++)
    for (j = 1; j <= cifre; j++)
      if (c[j] == i)
        f[i]++;
  for (i = 2; i <= 9; i++) {
    a = n*i; x = 0; e = 0;
    for (j = 0; j <= 9; j++)
      f2[j] = 0;
    while (a >= 10) {
      x++;
      c2[x] = a%10;
      a = a/10;
    }
    x++; cifre2 = x; c2[x] = a;
    if (cifre == cifre2) {
      for (x = 0; x <= 9; x++)
        for (j = 1; j <= cifre2; j++)
          if (c2[j] == x)
            f2[x]++;
      for (j = 0; j <= 9; j++)
        if (f[j] == f2[j])
          e++;
      if (e == 10) {
        if (not afisat) {
          fo << "DA" << endl; anagramabil = true;
          fo << i;
          afisat = true;
        }
        else
          fo << i;
      }
    }
  }
  if (not anagramabil)
    fo << "NU";
  return 0;
}
