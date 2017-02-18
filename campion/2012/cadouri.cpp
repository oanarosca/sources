nclude <fstream>

using namespace std;

int a[100];
int n, f, b, i, nrf, nrb;

int main () {
    ifstream fi("cadouri.in");
    ofstream fo("cadouri.out");
    fi >> f >> b >> n;
    for (i = 0; i < n; i++)
        fi >> a[i];
    for (i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            nrf++;
        else
            nrb++;
    if (nrf >= f)
        fo << 0 << endl;
    else
        fo << f-nrf << endl;
    if (nrb >= b)
        fo << 0;
    else
        fo << b-nrb;
    return 0;
}
