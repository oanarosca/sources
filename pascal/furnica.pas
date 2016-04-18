var
  fi, fo : text;
  a : array [1..101, 1..101] of integer;
  p : array [1..101, 1..101] of integer;
  n, l, c, pasi, k, d, s, max, nmax : integer;
begin
  assign (fi, 'furnica.in'); reset (fi);
  assign (fo, 'furnica.out'); rewrite (fo);
  readln (fi, n, k);
  for l := 1 to n do
    for c := 1 to n do
       a[l, c] := (l+c) mod 6;
  l := 1; c := 1; s := a[1,1]; p[1,1] := 1;
  for pasi := 1 to k do
    begin
      read (fi, d);
      case d of
        1 : dec (l);
        2 : begin dec (l); inc (c); end;
        3 : inc (c);
        4 : begin inc (l); inc (c); end;
        5 : inc (l);
        6 : begin inc (l); dec (c); end;
        7 : dec (c);
        8 : begin dec (l); dec (c); end;
      end;
      s := s+a[l, c]; a[l, c] := 0; inc (p[l, c]);
    end;
  max := p[1,1];
  for l := 1 to n do
    for c := 1 to n do
      if p[l, c] > max then
        max := p[l, c];
  for l := 1 to n do
    for c := 1 to n do
      if max = p[l, c] then
        inc (nmax);
  write (fo, s, ' ', nmax);
  close (fi); close (fo);
end.

1 1 2 1 2 2

1,1
1,2
1,3
2,3
2,4
