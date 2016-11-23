#include <iostream>

using namespace std;

int n, i, l, p, saispe;
string s;

int main () {
  cin >> s; l = s.length()-1; saispe = 1;
  for (i = l; i >= 0; i--) {
    if (s[i] >= 65) {
      p = 10+s[i]-65;
    }
    else
      p = s[i]-48;
    n += saispe*p;
    saispe *= 16;
  }
  cout << n;
}
