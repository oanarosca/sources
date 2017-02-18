nclude <fstream>

using namespace std;

int a[100], b[10];
long n, m, c, d, e, f, i, j;
int main () {
    ifstream fi ("cifra1.in");
    ofstream fo ("cifra1.out");
    fi >> n >> m;
    d = n; e = n;
    while (d >= 10) { // se numara cifrele numarului n
        d = d / 10;
        c++;
    }
    c++;
    for (i = c; i >= 1; i--) { // se scriu inr-un sir cifrele numarului n
        b[i] = e % 10;
        e = e / 10;
    }
    for (i = 1; i <= c; i++) { // se scriu cifrele nr. n, fiecare cifra de nr. de ori = cifra
        j = b[i];
        for (e = 1; e <= j; e++) {
            f++;
            a[f] = j;
        }
    }
    fo << a[m];
    return 0;
}
