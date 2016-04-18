var
  fi, fo : text;
  n, i, a, i1, i2 : integer;
  c : array [1..1000] of integer;
  s1, s2 : longint;
begin
  assign (fi, 'joc20.in'); reset (fi);
  assign (fo, 'joc20.out'); rewrite (fo);
  readln (fi, n);
  for i := 1 to n do
    read (fi, c[i]);
  i1 := 1; i2 := n;
  for i := 1 to n div 2 do
    begin
      read (fi, a);
      if a = 1 then
        begin
          s1 := s1+c[i1]; inc(i1);
        end
      else
        begin
          s1 := s1+c[i2]; dec(i2);
        end;
      read (fi, a);
      if a = 1 then
        begin
          s2 := s2+c[i1]; inc(i1);
        end
      else
        begin
          s2 := s2+c[i2]; dec(i2);
        end;
    end;
  if s1 > s2 then
    write (fo, s1, ' ', 1)
  else
    if s2 > s1 then
      write (fo, s2, ' ', 2)
    else
      write (fo, s1, ' ', 0);
  close (fi); close (fo);
end.
