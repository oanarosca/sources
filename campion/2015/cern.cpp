nclude <fstream>

using namespace std;

int t, sens, cerc;
char p;

int main () {
  ifstream fi("cern.in");
  ofstream fo("cern.out");
  fi >> p >> sens >> t;
  t %= 1080;
  switch (p) {
    case 'A':
      if (sens == 1)
        if (t < 180)
          fo << t << ' ' << 1, t = 0;
        else
          t -= 180, p = 'G', cerc = 2;
      else
        if (t < 120)
          fo << 360-t << ' ' << 1, t = 0;
        else
          t -= 120, p = 'I', cerc = 3;
    break;
    case 'B':
      if (sens == 1)
        if (t < 120)
          fo << t+60 << ' ' << 1, t = 0;
        else
          t -= 120, p = 'G', cerc = 2;
      else
        if (t < 180)
          fo << (360-(t-60)) % 360 << ' ' << 1, t = 0;
        else
          t -= 180, p = 'I', cerc = 3;
    break;
    case 'C':
      if (sens == 1)
        if (t < 180)
          fo << t+120 << ' ' << 2, t = 0;
        else
          t -= 180, p = 'H', cerc = 3;
      else
        if (t < 120)
          fo << 120-t << ' ' << 2, t = 0;
        else
          t -= 120, p = 'G', cerc = 1;
    break;
    case 'D':
      if (sens == 1)
        if (t < 120)
          fo << 180+t << ' ' << 2, t = 0;
        else
          t -= 120, p = 'H', cerc = 3;
      else
        if (t < 180)
          fo << 180-t << ' ' << 2, t = 0;
        else
          t -= 180, p = 'G', cerc = 1;
    break;
    case 'E':
      if (sens == 1)
        if (t < 180)
          fo << (t+240) % 360 << ' ' << 3, t = 0;
        else
          t -= 180, p = 'I', cerc = 1;
      else
        if (t < 120)
          fo << 240-t << ' ' << 3, t = 0;
        else
          t -= 120, p = 'H', cerc = 2;
    break;
    case 'F':
      if (sens == 1)
        if (t < 120)
          fo << (300+t) % 360 << ' ' << 3, t = 0;
        else
          t -= 120, p = 'I', cerc = 1;
      else
        if (t < 180)
          fo << 300-t << ' ' << 3, t = 0;
        else
          t -= 180, p = 'H', cerc = 2;
  }
  sens = -sens;
  while (t) {
    switch (p) {
      case 'G':
        if (sens == 1)
          if (cerc == 1)
            if (t < 60)
              fo << 180+t << ' ' << 1, t = 0;
            else
              t -= 60, p = 'I', cerc = 3;
          else
            if (t < 300)
              fo << t << ' ' << 2, t = 0;
            else
              t -= 300, p = 'H', cerc = 3;
        else
          if (cerc == 1)
            if (t < 300)
              fo << (540-t) % 360 << ' ' << 1, t = 0;
            else
              t -= 300, p = 'I', cerc = 3;
          else
            if (t < 60)
              fo << 360-t << ' ' << 2, t = 0;
            else
              t -= 60, p = 'H', cerc = 3;
      break;
      case 'H':
        if (sens == 1)
          if (cerc == 2)
            if (t < 60)
              fo << 300+t << ' ' << 2, t = 0;
            else
              t -= 60, p = 'G', cerc = 1;
          else
            if (t < 300)
              fo << 120+t << ' ' << 3, t = 0;
            else
              t -= 300, p = 'I', cerc = 1;
        else
          if (cerc == 2)
            if (t < 300)
              fo << (300-t) % 360 << ' ' << 2, t = 0;
            else
              t -= 300, p = 'G', cerc = 1;
          else
            if (t < 60)
              fo << 120-t << ' ' << 3, t = 0;
            else
              t -= 60, p = 'I', cerc = 1;
      break;
      case 'I':
        if (sens == 1)
          if (cerc == 1)
            if (t < 300)
              fo << (240+t) % 360 << ' ' << 1, t = 0;
            else
              t -= 300, p = 'G', cerc = 2;
          else
            if (t < 60)
              fo << 60+t << ' ' << 3, t = 0;
            else
              t -= 60, p = 'H', cerc = 2;
        else
          if (cerc == 1)
            if (t < 60)
              fo << 240-60 << ' ' << 1, t = 0;
            else
              t -= 60, p = 'G', cerc = 2;
          else
            if (t < 300)
              fo << (420-t) % 360 << ' ' << 3, t = 0;
            else
              t -= 300, p = 'H', cerc = 2;
      break;
    }
    sens = -sens;
  }
  return 0;
}
