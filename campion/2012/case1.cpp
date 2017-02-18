nclude <fstream>

using namespace std;

short n, i, gr1, gr2, gr3, b, f, c;
int a;

int main ()
{
    ifstream fi("case1.in");
    ofstream fo("case1.out");
    fi >> n;
    for (i = 1; i <= n; i++)
    {
        fi >> a;
        c += a % 10;
        a = a / 10;
        f += a % 10;
        a = a / 10;
        b += a % 10;
        switch (a / 10)
        {
        case 1:
            gr1++; break;
        case 2:
            gr2++; break;
        case 3:
            gr3++; break;
        }
    }
    fo << gr1 << endl;
    fo << gr2 << endl;
    fo << gr3 << endl;
    fo << b << endl;
    fo << f << endl;
    fo << c;
    return 0;
}
