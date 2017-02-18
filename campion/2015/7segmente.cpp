nclude <fstream>

using namespace std;

int e, n, i, a[201], suma, b[201], j;
int cif[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string s;
bool egal;

int main () {
  ifstream fi("7segmente.in");
  ofstream fo("7segmente.out");
  fi >> s >> e; n = s.length();
  for (i = 0; i <= n-1; i++)
    a[i+1] = s[i]-48, suma += cif[a[i+1]], b[i+1] = 1, e -= 2;
  fo << suma << ' '; i = 0; egal = true;
  while (e and i <= n) {
    i++;
    if (cif[a[i]]-2 <= e and egal)
      e -= cif[a[i]]-2, b[i] = a[i];
    else
      if (egal) {
        egal = false;
        for (j = a[i]-1; j >= 1; j--)
          if (cif[j]-2 <= e)
            break;
        b[i] = j; e -= (cif[j]-2);
      }
      else {
        for (j = 9; j >= 1; j--)
          if (cif[j]-2 <= e)
            break;
        b[i] = j; e -= (cif[j]-2);
      }
  }
  for (i = 1; i <= n; i++)
    if (b[i])
      fo << b[i];
  return 0;
}
