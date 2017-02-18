nclude <fstream>

using namespace std;

int n, k, i, c[10], p10[10], cifre, nk, a[10], cc, pcc, cn;

int main () {
  ifstream fi("aparitii.in");
  ofstream fo("aparitii.out");
  fi >> n >> k;
  p10[0] = 1; p10[1] = 10;
  for (i = 2; i <= 9; i++)
    p10[i] = p10[i-1]*10;
  for (i = 1; n >= p10[i]; i++)
    c[i] = p10[i-1]+9*c[i-1];
  cifre = i; cn = n;
  for (i = 1; i <= cifre; i++) {
    a[cifre-i+1] = cn%10; //a contine cifrele lui n
    cn /= 10;
  }
  for (i = 1; i <= cifre; i++) {
    cc = a[i]; pcc = cifre-i+1; //cifra curenta & puterea cifrei curente
    if (cc < k)
      nk += cc*c[pcc-1];
    if (cc == k) {
      nk += k*c[pcc-1]+n % p10[pcc-1]+1;
      break;
    }
    if (cc > k)
      nk += p10[pcc-1]+(cc-1)*c[pcc-1];
  }
  fo << nk;
  return 0;
}
