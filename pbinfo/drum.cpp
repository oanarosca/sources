#include <fstream>
#include <iostream>

using namespace std;

int lin, col, v, i, j, k, n, val, m[502][502], l, c, u, d;
bool gata;
int dl[] = {0, -1, 0, 1, 0};
int dc[] = {0, 0, 1, 0, -1};

bool valid (int l, int c) {
  return 1 <= l and l <= lin and 1 <= c and c <= col;
}

void fill (int l, int c, int val) {
  if (gata) return;
  if (valid(l, c))
    if (m[l][c] == 3) {
      m[l][c] = val;
      fill (l-1, c, val);
      fill (l, c+1, val);
      fill (l+1, c, val);
      fill (l, c-1, val);
    }
    else if ((val == 1 and m[l][c] == 2) or (val == 2 and m[l][c] == 1)) {
      gata = 1; return;
    }
}

int main () {
  ifstream fi("drum.in");
  ofstream fo("drum.out");
  fi >> lin >> col >> v;
  for (i = 1; i <= v; i++) {
    fi >> n;
    for (j = 1; j <= n; j++) {
      fi >> val; u = d = 0;
      //val % lin == 0 ? l = val/lin, c = col : l = val/lin+1, c = val%lin;
      if (val % col == 0) l = val/col, c = col;
      else l = val/col+1, c = val % col;
      m[l][c] = i;
      m[l][c] = 3;
      for (k = 1; k <= 4; k++)
        if (m[l+dl[k]][c+dc[k]] == 1)
          u++;
        else
          if (m[l+dl[k]][c+dc[k]] == 2)
            d++;
      if (l == 1) u++;
      if (l == lin) d++;
      if (u and d) {
        fo << i; return 0;
      }
      else
        if (u)
          fill (l, c, 1), m[l][c] = 1;
        else if (d)
          fill (l, c, 2), m[l][c] = 2;
      if (gata) {
        fo << i; return 0;
      }
      /*for (l = 1; l <= lin; l++) {
        for (c = 1; c <= col; c++)
          cout << m[l][c] << ' ';
        cout << endl;
      }
      cout << endl;*/
    }
  }
  for (l = 1; l <= lin; l++) {
    for (c = 1; c <= col; c++)
      fo << m[l][c] << ' ';
    fo << endl;
  }
  return 0;
}
