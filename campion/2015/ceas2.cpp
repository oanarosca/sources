nclude <fstream>

using namespace std;

int l, c, b, cod, o[5], t, i;
char m[10][10];
long long ora;
bool prim = true;

void transformare () {
  int nr = 0;

  if (prim)
    c = 0, prim = false;
  l = 4; c++;
  if (i % 2 == 1)
    nr = o[(i+1)/2]/10;
  else
    nr = o[i/2] % 10;
  while (nr) {
    if (nr % 2 == 1)
      m[l][c] = 'o';
    nr /= 2; l--;
  }
}

int main () {
  ifstream fi("ceas2.in");
  ofstream fo("ceas2.out");
  for (l = 1; l <= 4; l++) {
    for (c = 1; c <= 8; c++)
      fi.get(m[l][c]);
    fi.get();
  }
  for (c = 1; c <= 8; c++) {
    cod = 0;
    for (l = 1; l <= 4; l++) {
      if (m[l][c] == 'o')
        b = 1, cod = cod*2+b;
      else
        if (m[l][c] == 'x')
          b = 0, cod = cod*2+b;
    }
    if (c % 2 == 1)
      o[(c+1)/2] = cod;
    else
      o[c/2] *= 10, o[c/2] += cod;
  }
  ora = (long long)o[4]+o[3]*100+o[2]*6000+o[1]*360000; // long long!
  fi >> t;
  ora += t;
  o[1] = ora/360000; ora %= 360000;
  o[2] = ora/6000; ora %= 6000;
  o[3] = ora/100; ora %= 100;
  o[4] = ora;
  o[3] += o[4]/100; o[4] %= 100;
  o[2] += o[3]/60; o[3] %= 60;
  o[1] += o[2]/60; o[2] %= 60;
  o[1] %= 24;
  for (l = 1; l <= 4; l++)
    for (c = 2; c <= 8; c++)
      m[l][c] = 'x';
  m[3][1] = m[4][1] = 'x';
  m[1][1] = m[2][1] = m[1][3] = m[1][5] = ' ';
  for (i = 1; i <= 8; i++)
    transformare();
  for (l = 1; l <= 4; l++) {
    for (c = 1; c <= 8; c++)
      fo << m[l][c];
    fo << '\n';
  }
  return 0;
}
