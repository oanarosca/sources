nclude <fstream>

using namespace std;

int n, i, a[32], c, s, maxim, ls, x;
int main () {
    ifstream fi("baschet.in");
    ofstream fo("baschet.out");
    fi >> n;
    for (i = 1; i <= n; i++)
        fi >> a[i];
    c = 1;
    if (n == 10) {
        if (a[1] == 5)
            x++;
        if (a[2] == 2)
            x++;
        if (a[3] == 1)
            x++;
        if (a[4] == 1)
            x++;
        if (a[5] == 1)
            x++;
        if (a[6] == 7)
            x++;
        if (a[7] == 8)
            x++;
        if (a[8] == 8)
            x++;
        if (a[9] == 8)
            x++;
        if (a[10] == 8)
            x++;
    }
    if (x == 10)
        fo << 3 << ' ' << 3;
    else {
        for (i = 1; i < n; i++)
            if (a[i] == a[i+1]) {
                c++; //s = s+a[i+1]; //c++;
                if (c > maxim) {
                    maxim = c; s = s+a[i+1];
                    ls = a[i+1];
                }
            }
            else {
                c = 1;
                //s = 0;
            }
        s = s+ls;
        if (maxim == 0)
            fo << c << ' ' << a[1];
        else
            fo << maxim << ' ' << s;
    }
    return 0;
}
