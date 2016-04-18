var
  fi, fo : text;
  s, p, i, j, n : integer;
begin
  assign (fi, 'ucif.in'); reset (fi);
  assign (fo, 'ucif.out'); rewrite (fo);
  read (fi, n);
  for i := 1 to n do
    begin
      p := 1;
      for j := 1 to i do
        p := p*i mod 10;
      s := (s+p) mod 10;
    end;
  write (fo, s);
  close (fi); close (fo);
end.
