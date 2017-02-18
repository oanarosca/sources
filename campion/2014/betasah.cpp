nclude <fstream>

using namespace std;

int n, a2[1001], b2[1001], ramase, stinse, aprinse, i, j, aux, a, b, suma[1001], maxim;

int main () {
  ifstream fi("becuri2.in");
  ofstream fo("becuri2.out");
  fi >> n >> a >> b;
  for (j = 1; j <= n; j++) {
    a2[j] = a%2; a /= 2;
  }
  for (j = 1; j <= n; j++) {
    b2[j] = b%2; b /= 2;
  }
  for (i = 1; i <= n/2; i++) {
    aux = a2[i]; a2[i] = a2[n-i+1]; a2[n-i+1] = aux;
    aux = b2[i]; b2[i] = b2[n-i+1]; b2[n-i+1] = aux;
  }
  for (i = 1; i <= n; i++)
    if (a2[i] != b2[i]) {
      if (a2[i] > b2[i])
        stinse++;
      else
        aprinse++;
    }
  for (i = 1; i <= n; i++)
    suma[i] = a2[i]+b2[i];
  ramase = 1;
  for (i = 1; i <= n-1; i++)
    if ((suma[i] == 2) and (suma[i+1] == 2)) {
      ramase++;
      if (ramase > maxim)
        maxim = ramase;
    }
    else
      ramase = 1;
  fo << stinse << ' ' << aprinse << ' ';
  if (maxim == 0)
    fo << 1;
  else
    fo << maxim;
  return 0;
}
