nclude <fstream>

using namespace std;

int n, m, i, aux, a[2002], s;
bool ordonat;

int main () {
    ifstream fi("arme.in");
    ofstream fo("arme.out");
    fi >> n >> m;
    for (i = 1; i <= n; i++)
        fi >> a[i];
    for (i = 1; i <= m; i++)
        fi >> a[n+i];
    do {
        ordonat = true;
        for (i = 1; i <= n+m-1; i++)
            if (a[i] < a[i+1]) {
                aux = a[i]; a[i] = a[i+1]; a[i+1] = aux;ordonat = false;
            }
    }
    while (not ordonat);
    for (i = 1; i <= n; i++)
        s = s+a[i];
    fo << s;
    return 0;
}
