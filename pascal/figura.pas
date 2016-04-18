var
  fi, fo : text;
  d, i, l, c, j : shortint;
  n, p : integer;
  m : array [0..21, 0..21] of integer;
begin
  assign (fi, 'figura.in'); reset (fi);
  assign (fo, 'figura.out'); rewrite (fo);
  readln (fi, d); readln (fi, n);
  for i := 1 to n do
    begin
      readln (fi, l, c);
      m[l,c] := 1;
    end;
  for l := 1 to 19 do
    for c := 1 to 19 do
      if m[l,c] = 1 then
        begin
          i := l; j := c;
          inc (i);
          if m[i,c] = 0 then
            inc (p);
          i := i-2;
          if m[i,c] = 0 then
            inc (p);
          inc (j);
          if m[l,j] = 0 then
            inc (p);
          j:= j-2;
          if m[l,j] = 0 then
            inc (p);
        end;
  if n = 1 then
    write (fo, 4)
  else
    write (fo, p);
  close (fi); close (fo);
end.
