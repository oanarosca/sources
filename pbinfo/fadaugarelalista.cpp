void adaugare (nod* &prim, int x) {
  nod* p = new nod, *q = new nod;

  p->info = x;
  p->urm = 0;
  if (!prim) {
    prim = p;
    return;
  }
  q = prim;
  while (q->urm)
    q = q->urm;
  q->urm = p;
}