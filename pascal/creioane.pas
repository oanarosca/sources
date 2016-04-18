var
  fi, fo : text;
  a, b, niv : array [1..9000] of integer;
  n, i, max, ncsn : integer;
begin
  assign (fi, 'creioane.in'); reset (fi);
  assign (fo, 'creioane.out'); rewrite (fo);
  readln (fi, n);
  for i := 1 to n do
    readln (fi, a[i], b[i]);
  repeat
    for i := 1 to n do
      if niv[i] = 0 then // nu am stabilit nivelul pentru i
        if a[i] <> 0 then // i sta pe a[i]
          if niv[a[i]] <> 0 then
            begin
              niv[i] := niv[a[i]]+1; inc(ncsn);
            end
          else // nimic
        else
          begin
            niv[i] := 1; inc(ncsn) // numarul de creioane pentru care stim nivelul
          end
  until ncsn = n;
  for i := 1 to n do
    if niv[i] > max then
      max := niv[i];
  write (fo, max);
  close (fi); close (fo);
end.


4 5
0 0
0 0
2 3
2 3

3 1 1 2 2
1 2 3 4 5



2 7
0 0
0 0
2 7
4 6
2 7
0 0

2 1 1 2 3 2 1
1 2 3 4 5 6 7
