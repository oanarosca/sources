void afisare (nod* prim) {
  nod* p;

  p = prim;
  while (p) {
    cout << p->info << ' ';
    p = p->urm;
  }
}