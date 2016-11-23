int numarare (nod* prim) {
  nod* p, *q;
  int count = 0;

  p = prim;
  while (p) {
    q = p->urm;
    while (q) {
      int d = p->info, i = q->info, r;
      do {
        r = d % i;
        d = i;
        i = r;
      } while (i);
      if (d == 1)
        count++;
      q = q->urm;
    }
    p = p->urm;
  }
  return count;
}