nclude <fstream>

using namespace std;

int n;

int main() {
    ifstream fi ("capete.in");
    ofstream fo ("capete.out");
    fi >> n;
    fo << n*5;
    return 0;
}
