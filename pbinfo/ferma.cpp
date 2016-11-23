#include <fstream>

using namespace std;

int t, lin, col, l, c, z[403][403], zone, k, maxim, m[403][403], lmax, cmax, sn;
int i, li, ci, j, lj, cj;
char ch[403][403], cul;
int dl[] = {0, -1, 0, 1, 0};
int dc[] = {0, 0, 1, 0, -1};
bool ok;

void fill (int lv, int cv, int nrz) { // numarul zonei, linie vecin, coloana vecin
  if (not z[lv][cv] and ch[lv][cv] == ch[l][c]) {
    k++; z[lv][cv] = nrz;
    fill(lv-1, cv, nrz);
    fill(lv, cv+1, nrz);
    fill(lv+1, cv, nrz);
    fill(lv, cv-1, nrz);
  }
}
void fill2 (int lv, int cv, int nrz) { // aici nrz are rol de suprafata
  if (not m[lv][cv] and ch[lv][cv] == ch[l][c]) {
    m[lv][cv] = nrz;
    fill2(lv-1, cv, nrz);
    fill2(lv, cv+1, nrz);
    fill2(lv+1, cv, nrz);
    fill2(lv, cv-1, nrz);
  }
}

int main () {
  ifstream fi("ferma.in");
  ofstream fo("ferma.out");
  fi >> t >> lin >> col;
  for (l = 1; l <= lin; l++) {
    for (c = 1; c <= col; c++)
      fi >> ch[l][c];
    fi.get();
  }
  for (l = 0; l <= lin+1; l++)
    z[l][0] = z[l][col+1] = m[l][0] = m[l][col+1] = -1;
  for (c = 0; c <= col+1; c++)
    z[0][c] = z[lin+1][c] = m[l][0] = m[l][col+1] = -1;
  for (l = 1; l <= lin; l++)
    for (c = 1; c <= col; c++) {
      if (not z[l][c]) { // zone
        zone++; k = 0; // k numara cate patratele are zona
        fill (l, c, zone);
        maxim = max(maxim, k);
        if (t == 2)
          fill2 (l, c, k);
      }
    }
  if (t == 1) {
    fo << maxim; return 0;
  }
  for (l = 1; l <= lin; l++)
    for (c = 1; c <= col; c++)
      for (i = 1; i <= 4; i++)
        if (m[l+dl[i]][c+dc[i]] > 0 and z[l][c] != z[l+dl[i]][c+dc[i]]) { // sa nu fie -1
          li = l+dl[i], ci = c+dc[i]; sn = 0; // suma noua
          for (j = i; j <= 4; j++)
            if (m[l+dl[j]][c+dc[j]] > 0) {
              lj = l+dl[j], cj = c+dc[j];
              if (j == i)
                sn = m[li][ci]+1; // +1 pentru patratelul nou adaugat
              else if (ch[lj][cj] == ch[li][ci]) {
                ok = true;
                for (k = j-1; k >= i; k--)
                  if (z[l+dl[k]][c+dc[k]] == z[lj][cj]) ok = false; // daca sunt din aceeasi zona
                if (ok)
                  sn += m[lj][cj];
              }
              if (sn > maxim)
                maxim = sn, lmax = l, cmax = c, cul = ch[li][ci];
            }
        }
  fo << lmax << ' ' << cmax << '\n' << cul;
  /*for (l = 1; l <= lin; l++) {
    for (c = 1; c <= col; c++)
      fo << m[l][c] << ' ';
    fo << '\n';
  }*/
  return 0;
}
