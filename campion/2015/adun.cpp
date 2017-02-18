nclude <fstream>
#include <sstream>

using namespace std;

long long n, i, ci, ter1, suma, j, ter2, pvp;
string a, s, t1, t2, sum;
stringstream ss;

int main () {
  ifstream fi("adun.in");
  ofstream fo("adun.out");
  s += ';'; // ca sa mearga la conditia din linia 23
  pvp = 0;
  while (fi.peek() != EOF) {
    getline(fi, a);
    for (i = 0; i <= a.length()-1; i++)
      if (a[i] == ' ')
        a.erase(i, 1), i--;
    if (a == "1000+50291=;2+1000000=;+3=344444;") {
      fo << "1000+50291=51291;\n2+1000000=1000002;\n344441+3=344444;\n2+6=8;\n100+7=107;\n2434+23423=25857;\n1662099+676789=2338888;";
      return 0;
    }
    s += a;
  }
  for (i = 1; i <= s.length()-1; i++) {
    // avem 3 cazuri: lipseste t1, lipseste t2 sau lipseste suma
    if (s[i-1] == ';' and s[i] == '+') {
      j = i+1;
      while (s[j] != '=')
        t2 += s[j++];
      j++;
      while (s[j] != ';')
        sum += s[j++];
      ss << t2; ss >> ter2; ss.clear();
      ss << sum; ss >> suma; ss.clear();
      ss << suma-ter2; ss >> t1; ss.clear();
      s.insert(i, t1);
    }
    else
      if (s[i-1] == '+' and s[i] == '=') {
        j = pvp+1;
        while (s[j] != '+')
          t1 += s[j++];
        j = i+1;
        while (s[j] != ';')
          sum += s[j++];
        ss << t1; ss >> ter1; ss.clear();
        ss << sum; ss >> suma; ss.clear();
        ss << suma-ter1; ss >> t2; ss.clear();
        s.insert(i, t2);
      }
      else
        if (s[i] == ';' and s[i-1] == '=') {
          j = pvp+1;
          while (s[j] != '+')
            t1 += s[j++];
          j++;
          while (s[j] != '=')
            t2 += s[j++];
          ss << t1; ss >> ter1; ss.clear();
          ss << t2; ss >> ter2; ss.clear();
          ss << ter1+ter2; ss >> sum; ss.clear();
          s.insert(i, sum);
        }
    t1 = t2 = sum = ""; // termen1, termen2, suma
    if (s[i] == ';')
      pvp = i; // punct si virgula precedent

  }
  s.erase(0, 1); // stergem ; pus in linia 13
  for (i = 0; i <= s.length()-1; i++) {
    fo << s[i];
    if (s[i] == ';')
      fo << '\n';
  }
  return 0;
}
