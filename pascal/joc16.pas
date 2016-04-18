var
  fi, fo : text;
  n, x, y, i, j, s, t, a : word;
  b, r : array [1..40000] of integer;
  gata : boolean;
begin
  assign (fi, 'joc16.in'); reset (fi);
  assign (fo, 'joc16.out'); rewrite (fo);
  read (fi, n, x, y);
  i := 1; j := 1;
  b[1] := 1; r[1] := 1;
  repeat
    if i+x > n then
      i := i+x-n
    else
      i := i+x;
    if b[i] = 1 then
      gata := true;
    b[i] := 1;
    if j-y < 1 then
      j := j-y+n
    else
      j := j-y;
    if r[j] = 1 then
      gata := true;
    r[j] := 1; inc (s);
  until (j = i) or gata;
  for a := 1 to n do
    if (b[a] = 0) and (r[a] = 0) then
      inc (t);
  write (fo, t, ' ', s, ' ', i, ' ', j);
  close (fi); close (fo);
end.
