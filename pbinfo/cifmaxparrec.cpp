int cifmaxpar (int n) {
  if (n < 10) {
    if (n % 2 == 1) return -1;
    return n;
  }
  if ((n % 10) % 2 == 0)
    return max(cifmaxpar(n/10), n % 10);
  else return cifmaxpar(n/10);
}