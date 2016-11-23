#include <iostream>
#include <cstring>

using namespace std;

int i, l;
char s[256];

int main () {
  cin.get(s, 256); l = strlen(s)-1;
  cout << (char)(s[i]-32);
  for (i = 1; i <= l-1; i++) {
    if ((s[i] != ' ' and s[i-1] == ' ') or (s[i] != ' ' and s[i+1] == ' '))
      cout << (char)(s[i]-32);
    else
      cout << s[i];
  }
  cout << (char)(s[l]-32);
}
