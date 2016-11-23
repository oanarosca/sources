void adaugareInainte (nod* &prim, int x) {
  nod* p = new nod;

  p->info = x;
  p->urm = 0;
  if (!prim) {
    prim = p;
    return;
  }
  p->urm = prim;
  prim = p;
}