var
  fi, fo : text;
  n, p, k, i, zile, s, z, j : integer;
begin
  assign (fi, 'pinochio.in'); reset (fi);
  assign (fo, 'pinochio.out'); rewrite (fo);
  read (fi, n, p, k);
  s := k div 7;
  zile := k mod 7;
  for i := 1 to s do
    begin
      z := 0;
      repeat
        n := n+p;
        inc (z);
      until z = 5;
      for j := 1 to 2 do
        begin
          dec (n);
        end;
    end;
  z := 0;
  for i := 1 to zile do
    n := n+p;
  if i = 6 then
    n := n-(p+1);
  write (fo, n);
  close (fi); close (fo);
end.
