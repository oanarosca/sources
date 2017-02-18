nclude <fstream>
#include <cstdlib>

using namespace std;

int c, l, intensitate, cc, lc, r, ca, n[10001], maxim, i, maxim_a, mca, numere;

int main () {
  freopen ("cladiri1.in", "r", stdin);
  ofstream fo("cladiri1.out");
  scanf("%d %d %d", &c, &l, &intensitate); //fi >> c >> l >> intensitate;
  while ((numere = scanf("%d %d %d", &cc, &lc, &r)) == 3) {
    if (abs(l-lc) > abs(c-cc)) {
      if (r <= intensitate-abs(l-lc)) {
        n[abs(l-lc)]++, ca++;
        if (abs(l-lc) > maxim)
          maxim = abs(l-lc);
      }
    }
    else
      if (r <= intensitate-abs(c-cc)) {
        n[abs(c-cc)]++, ca++;
        if (abs(c-cc) > maxim)
          maxim = abs(c-cc);
      }
  }
    /*if ((c == cc) or ((c != cc) and (l != lc))) {
      if (r <= intensitate-abs(l-lc)) {
        n[abs(l-lc)]++, ca++;
        if (abs(l-lc) > maxim)
          maxim = abs(l-lc);
      }
    }
    else
      if ((l == lc) and (r <= intensitate-abs(c-cc))) {
        n[abs(c-cc)]++, ca++;
        if (abs(c-cc) > maxim)
          maxim = abs(c-cc);
      }*/
  fo << ca << '\n';
  for (i = 0; i <= maxim; i++)
    if (n[i] > maxim_a)
      maxim_a = n[i]; //, mca = 1; //maxim cladiri afectate
    //else
      //if (n[i] == maxim_a)
        //mca++;
  fo << maxim_a << '\n';
  for (i = 0; i <= maxim; i++)
    if ((n[i] == maxim_a) and (maxim_a > 0))
      fo << i << ' ';
  return 0;
}
