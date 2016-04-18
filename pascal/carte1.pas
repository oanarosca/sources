var
  fi, fo : text;
  a : array [1..10001] of integer;
  n, i, p, zmax, max, zile : integer;
begin
  assign (fi, 'carte1.in'); reset (fi);
  assign (fo, 'carte1.out'); rewrite (fo);
  readln (fi, n);
  for i := 1 to n do
    begin
      read (fi, p);
      a[p] := i;
    end;
  p := 0; zile := 1; zmax := 1;
  for i := 1 to n do
    begin
      if a[i] < a[i+1] then
        begin
          inc (p);
          if p > max then
            begin
              max := p;
              zmax := zile;
            end;
        end
      else
        begin
          inc (zile);
          p := 0;
        end;
    end;
  write (fo, zile-1, ' ', zmax, ' ', max+1);
  close (fi); close (fo);
end.
