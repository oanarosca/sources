nclude <fstream>

using namespace std;

int d, n, nr, s, i, e, t;
ifstream fi("alo.in");
ofstream fo("alo.out");

int main ()
{
    fi >> e >> n;
    t = e;
    for (i = 1; i <= n; i++)
    {
        fi >> nr >> d;
        if (nr % 10 == 9)
            t = t+0;
        else if (nr / 10000 == 1)
            t = t-2*d;
        else
            t = t+1*d;
    }
    fo << t;
    return 0;
}
