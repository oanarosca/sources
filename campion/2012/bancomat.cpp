nclude <fstream>

using namespace std;

int main () {
    long i, n, s, b;
    ifstream fi ("bancomat.in");
    ofstream fo ("bancomat.out");
    fi >> s; fi >> n;
    for (i = 1; i <= n; i++) {
        fi >> b;
        if (b % 10 == 2)
            s = s+(b / 10);
        else
            if ((b % 10 == 3) and (s >= (b / 10)))
                s = s-(b / 10);
    }
    fo << s;
return 0;
}
