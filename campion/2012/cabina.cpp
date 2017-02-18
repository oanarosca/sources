nclude <fstream>

using namespace std;

int n, a, b, i, p, bz, c, d, s, e, f;
int main () {
    ifstream fi("cabina.in");
    ofstream fo("cabina.out");
    fi >> n >> a >> b >> c >> d;
    for (i = 1; i <= n-1; i++) {
          p = p+b;
          if (c > a)
            bz = bz+(3*(c-a));
          else {
              bz = bz+(a-c);
          }
          fi >> e >> f;
          if (e != 0) {
            if ((a < c) and (c > e))
              s = s+1;
            else
              if ((a > c) and (c < e))
                s++;
          }
          a = c; b = d; c = e; d = f;
    }
      fo << p << endl;
      fo << bz << endl;
      fo << s;
    return 0;
}
