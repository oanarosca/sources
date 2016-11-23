#include <iostream>
#include <cstring>

using namespace std;

int i, l;
char s[25];

int main () {
  cin >> s; l = strlen(s);
  for (i = 0; i <= l-1; i++) {
    if (strchr("aeiou", s[i]))
      cout << (char)(s[i]-32);
    else
      cout << s[i];
  }
}
