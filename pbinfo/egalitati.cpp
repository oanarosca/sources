#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct val {
  char l; long long v;
}a[101];

long long n, i, j;
string s[101], num;
bool rez[101];
stringstream ss;

bool cmp (val a, val b) {
  return a.l < b.l;
}

void sol (int i) {
  int j, cont = 0, v[] = {0, 0, 0}, semn = 'a', k;

  a[i].l = s[i][0];
  for (j = 2; j <= s[i].length()-1; j++) {
    if (s[i][j] == '+' or s[i][j] == '*')
      semn = s[i][j];
    if ('0' <= s[i][j] and s[i][j] <= '9') {
      num = "", ss.clear();
      while ('0' <= s[i][j] and s[i][j] <= '9' and j <= s[i].length()-1)
        num += s[i][j], j++;
      ss << num; ss >> v[++cont]; j--;
    }
    if ('a' <= s[i][j] and s[i][j] <= 'z') {
      for (k = 1; k <= n; k++)
        if (s[k][0] == s[i][j])
          break;
      if (not rez[k])
        sol(k);
      v[++cont] = a[k].v;
    }
  }
  if (semn == '+')
    a[i].v = v[1]+v[2];
  else if (semn == '*')
    a[i].v = v[1]*v[2];
  else
    a[i].v = v[1];
  rez[i] = true;
}

int main () {
  ifstream fi("egalitati.in");
  ofstream fo("egalitati.out");
  fi >> n; fi.get();
  for (i = 1; i <= n; i++) {
    getline (fi, s[i]);
    for (j = 0; j <= s[i].length()-1; j++)
      if (s[i][j] == ' ')
        s[i].erase(j, 1), j--;
  }
  for (i = 1; i <= n; i++)
    if (not rez[i])
      sol(i);
  sort(a+1, a+n+1, cmp);
  for (i = 1; i <= n; i++)
    fo << a[i].l << " = " << a[i].v << '\n';
  return 0;
}
