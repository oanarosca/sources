nclude <fstream>

using namespace std;

int a, b[501], i, cmmmc2, n, ca, r, cmmdc, cb, maxim;

void cmmmc () {

  ca = a; cb = b[i];
  do {
    r = ca % cb;
    ca = cb; cb = r;
  } while (cb != 0);
  cmmdc = ca;
  cmmmc2 = a*(b[i]/cmmdc); a = cmmmc2;
}

int main () {
  ifstream fi("canguri.in");
  ofstream fo("canguri.out");
  fi >> n; fi >> a; b[1] = a;
  for (i = 2; i <= n; i++) {
    fi >> b[i]; cmmmc();
    if (b[i] > maxim)
      maxim = b[i];
  }
  if (cmmmc2 >= 3*maxim)
    fo << cmmmc2;
  else {
    for (i = 2; cmmmc2*i < 3*maxim; i++);
    fo << cmmmc2*i;
  }
  return 0;
}
