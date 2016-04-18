var
  a : array [1..1000] of integer;
  b : array [1..1000] of integer;
  c : array [1..1000] of integer;
  fi, fo : text;
  h, n, i, o, n1, s, n2 : integer;
begin
  assign (fi, 'concurs3.in'); reset (fi);
  assign (fo, 'concurs3.out'); rewrite (fo);
  readln (fi, h); readln (fi, n);
  for i :=  1 to n do
    read (fi, a[i]);
  if (n = 1) and (a[n] = h) then
    begin
      writeln (fo, 'DA');
      writeln (fo, 1);
      if ((a[n] div 100) = (h div 100)) and ((a[n] div 10) = (h div 10)) then
        write (fo, 1)
      else
        write (fo, 0);
    end
  else
    begin
      for i := 1 to n do
        begin
          b[i] := a[i];
          c[i] := a[i];
        end;
      for i := 1 to n do
        begin
          if a[i] = h then
            begin
              writeln (fo, 'DA');
              inc(o);
            end
          else
            a[i] := 0;
        end;
      for i := 1 to n do
        if a[i] = 0 then
          o := o+0;
      if o = 0 then
        writeln (fo, 'NU');
      for i := 1 to n do
        begin
          b[i] := b[i] div 100;
          s := h div 100;
          if b[i] = s then
            inc (n1);
        end;
      for i := 1 to n do
        begin
          c[i] := c[i] div 10;
          c[i] := c[i] mod 10;
          s := h div 10; s := s mod 10;
          if (c[i] = s) and (b[i] = h div 100) then
            inc (n2);
        end;
      writeln (fo, n1); write (fo, n2);
    end;
  close (fi); close (fo);
end.
