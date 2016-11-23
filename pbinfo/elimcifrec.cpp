int elimcif (int n, int c) {
  if (n < 10) {
    if (n != c) return n;
  }
  if (n % 10 != c)
    return elimcif(n/10, c)*10+n % 10;
  else return elimcif(n/10, c);
}