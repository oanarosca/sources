nclude <fstream>

using namespace std;

int i, n, a[2001], b[2001], c[2002], ct, fa[2001], fb[2001], cont, cont2, cont3;
string s;

int main () {
  ifstream fi("bile3.in");
  ofstream fo("bile3.out");
  fi >> n; s = "";
  for (i = 1; i <= n; i++)
    fi >> a[i], fa[a[i]]++;
  for (i = 1; i <= n; i++)
    fi >> c[i];
  ct = c[1]; cont = cont3 = 1; // cautat; cont - contorul pentru a; cont2 -||- pt b; cont3 -||- pt c;
  while (ct) {
    if (fa[ct]) { // bila este in zona A
      while (a[cont] != ct)
         b[++cont2] = a[cont], fa[a[cont]]--, fb[a[cont]]++, cont++, s += 'I';
      fa[ct] = 0, ct = c[++cont3], s += "IO", cont++; // cont creste ca sa ajunga la pozitia urmatorului
    }
    else // bila este in zona B
      if (b[cont2] == ct) // atunci eliminam bila din zona B
        fb[ct]--, b[cont2] = 0, cont2--, s += 'O', ct = c[++cont3];
      else { // daca bila nu se afla deasupra tuturor, nu poate fi scoasa din zona B
        fo << "imposibil"; return 0;
      }
  }
  fo << s;
  return 0;
}
