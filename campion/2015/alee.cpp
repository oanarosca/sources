nclude <fstream>
#define infile "alee.in"
#define outfile "alee.out"

using namespace std;

ifstream fi(infile);
ofstream fo(outfile);

struct pozitie {
  short int lin, col;
};

pozitie ps, p, v, c[30701], pf; // pozitia de start, pozitia curenta, vecin, coada, poz fin
int i, n, cop, x1, yrezerva, x2, y2, m[180][180], prim, ultim, lin, col;
int dl[] = {0, -1, 0, 1, 0};
int dc[] = {0, 0, 1, 0, -1};

void citire() {
  fi >> n >> cop;
  for (i = 1; i <= cop; i++)
    fi >> lin >> col, m[lin][col] = -1;
  fi >> x1 >> yrezerva >> x2 >> y2;
  ps.lin = x1, ps.col = yrezerva;
  pf.lin = x2, pf.col = y2;
}

void bordare() {
  for (col = 0; col <= n+1; col++)
    m[0][col] = m[n+1][col] = -1;
  for (lin = 0; lin <= n+1; lin++)
    m[lin][0] = m[lin][n+1] = -1;
}

void rezolvare () {
  citire(); bordare();
  c[1] = ps; prim = ultim = 1; m[ps.lin][ps.col] = 1;
  while (prim <= ultim and m[pf.lin][pf.col] == 0) { // cat timp coada - nevida si nu s-a ajuns la final
    p = c[prim]; prim++;
    for (i = 1; i <= 4; i++) {
      v.lin = p.lin+dl[i]; v.col = p.col+dc[i];
      if (m[v.lin][v.col] == 0) {
        m[v.lin][v.col] = m[p.lin][p.col]+1;
        ultim++, c[ultim] = v;
      }
    }
  }
  fo << m[pf.lin][pf.col];
  /*for (lin = 1; lin <= 175; lin++) {
    for (col = 1; col <= 175; col++)
      fo << m[lin][col] << ' ';
    fo << '\n';
  }*/
}

int main () {
  rezolvare();
  return 0;
}
