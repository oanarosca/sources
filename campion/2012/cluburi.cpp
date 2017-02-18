nclude <fstream>

using namespace std;

int a, m, n, i, b;
int main () {
    ifstream fi("cluburi.in");
    ofstream fo("cluburi.out");
    fi >> n; a = n; m = 1;
    do {
  	if (a % 2 == 1)
        b++;
    a = a / 2;
    }
    while (a != 0);
  fo << b << endl;
  a = n;
  for (i = 1; i <= n; i++) {
      if (a % 2 == 1)
      	fo << m << ' ';
    	a = a / 2;
      m = m*2;
  }
    return 0;
}
