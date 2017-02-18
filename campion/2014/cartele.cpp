nclude <fstream>

using namespace std;

int n, cartele, l, c, m[51][51], a[51][51], aux, k, i, j, aux2[51][51];

bool identice () {
  k = 0;
  for (l = 1; l <= n; l++)
    for (c = 1; c <= n; c++)
      if (a[l][c] == m[l][c])
        k++;
  if (k == n*n)
    return true;
  else
    return false;
}

void rotire () { // in sensul acelor de ceas
  for (c = n; c >= 1; c--) // luam ultima coloana si o punem pe prima linie
    for (l = 1; l <= n; l++)
      aux2[n-c+1][l] = m[l][c];
  for (l = 1; l <= n; l++)
    for (c = 1; c <= n; c++)
      m[l][c] = aux2[l][c];
}

void inversare() { // inversarea se face pe coloana
  for (l = 1; l <= n; l++)
    for (c = 1; c <= n/2; c++)
      aux = m[l][c], m[l][c] = m[l][n-c+1], m[l][n-c+1] = aux;
}

int main () {
  freopen("cartele.in", "r", stdin); //ifstream fi("cartele.in");
  ofstream fo("cartele.out");
  scanf("%d%d", &n, &cartele); //fi >> n >> cartele;
  for (l = 1; l <= n; l++)
    for (c = 1; c <= n; c++)
      scanf("%d", &a[l][c]); //fi >> a[l][c];
  for (i = 1; i <= cartele; i++) {
    for (l = 1; l <= n; l++)
      for (c = 1; c <= n; c++)
        scanf("%d", &m[l][c]); //fi >> m[l][c];
    if (identice()) // sunt identice din prima
      fo << 1 << '\n';
    else {
      for (j = 1; j <= 3; j++) { // la 4 rotiri se revine la pozitia initiala
        rotire();
        if (identice())
          break;
      }
      if (identice()) // sunt identice dupa rotiri
        fo << 1 << '\n';
      else {
        inversare();
        for (j = 1; j <= 4; j++) { // intrucat nu am testat pozitia initiala, se fac 4 rotiri
          rotire();
          if (identice())
            break;
        }
        if (identice()) // sunt identice dupa rotiri
          fo << 1 << '\n';
        else
          fo << 0 << '\n';
      }
    }
  }
  return 0;
}
