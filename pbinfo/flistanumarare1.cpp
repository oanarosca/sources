int numarare (nod* &prim) {
  nod* p = new nod, *q = new nod;
  int count = 0;

  p = prim;
  while (p->urm) {
    q = p->urm;
    if (p->info == q->info)
      count++;
    p = p->urm;
  }
  return count;
}