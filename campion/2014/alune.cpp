nclude <fstream>

using namespace std;

int c, d, a1, a2, i, cmmmc_a, ad, minim;

int cmmdc (int d, int i) {
  int r;

  while (i > 0) {
    r = d % i;
    d = i; i = r;
  }
  return d;
}

int cmmmc (int a, int b) {
  int m, d;

  d = cmmdc(a,b);
  m = a/d*b;
  return m;
}

int main () {
  freopen ("alune.in", "r", stdin);
  ofstream fo("alune.out");
  scanf("%d %d", &c, &d); minim = 2000000001;
  if (c >= 2) {
    scanf("%d %d", &a1, &a2);
    if (a1 < minim)
      minim = a1;
    else
      if (a2 < minim)
        minim = a2;
  }
  else {
    scanf("%d", &a1); a2 = a1;
    if (a1 < minim)
      minim = a1;
  }
  cmmmc_a = cmmmc(a1, a2); //cmmmc anterior
  for (i = 1; i <= c-2; i++) {
    scanf("%d", &a1);
    if (a1 < minim)
      minim = a1;
    cmmmc_a = cmmmc(cmmmc_a, a1);
  }
  for (i = 1; i <= d; i++) {
    scanf("%d", &ad);
    if (ad % cmmmc_a < minim)
      fo << 1;
    else
      fo << 0;
  }
  return 0;
}
