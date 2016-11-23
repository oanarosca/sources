int numarare (nod* prim) {
  nod* p;
  int count = 0;

  p = prim;
  while (p)
    count++, p = p->urm;
  return count;
}