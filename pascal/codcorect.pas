var
  fi, fo : text;
  n, i, cifre, cifre2 : integer;
  c, c2, rest, cc : longint;
  a : array [1..20] of longint;
begin
  assign (fi, 'codcorect.in'); reset (fi);
  assign (fo, 'codcorect.out'); rewrite (fo);
  readln (fi, n);
  for i := 1 to n do
    begin
      read (fi, a[i]); c := a[i];
      cifre := 0;
      repeat
         c := c div 10;
         inc (cifre);
      until c < 10;
      inc (cifre);
      cc := c;
      if cifre mod 2 = 0 then
        write (fo, a[i], ' ')
      else
        if a[i] mod 10 > c then
          begin
            c2 := a[i] mod 10;
            cifre2 := 0;
            repeat
              c2 := c2*10;
              c := c*10;
              inc (cifre2);
            until cifre - cifre2 = 1;
            rest := a[i] - c;
            c2 := c2+rest;
            c2 := c2 - c2 mod 10; c2 := c2+cc;
            write (fo, c2, ' ');
          end
        else
          write (fo, a[i], ' ');
    end;
  close (fi); close (fo);
end.
