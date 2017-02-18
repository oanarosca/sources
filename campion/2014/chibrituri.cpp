nclude <fstream>

using namespace std;

int vi, oi, i, j, v, o, po, uo, pm, um, var;
int cv[] = {4, 2, 2, 2, 3, 2, 3, 2, 4, 3};
int co[] = {2, 0, 3, 3, 1, 3, 3, 1, 3, 3};
bool prima = true;

int main () {
  ifstream fi("chibrituri.in");
  ofstream fo("chibrituri.out");
  fi >> vi >> oi; // initiale
  for (i = 0; i <= 23; i++) {
    for (j = 0; j <= 59; j++) {
      v = o = 0;
      v += cv[i/10]+cv[i%10]+cv[j/10]+cv[j%10];
      o += co[i/10]+co[i%10]+co[j/10]+co[j%10];
      if ((v == vi) and (o == oi)) {
        var++;
        if (prima)
          prima = false, po = i, pm = j; // prima ora si primul minut
        uo = i, um = j; // ultima ora si ultimul minut
      }
    }
  }
  fo << var << '\n';
  if (po < 10)
    fo << 0 << po << ':';
  else
    fo << po << ':';
  if (pm < 10)
    fo << 0 << pm;
  else
    fo << pm;
  fo << '\n';
  if (uo < 10)
    fo << 0 << uo << ':';
  else
    fo << uo << ':';
  if (um < 10)
    fo << 0 << um;
  else
    fo << um;
  return 0;
}
