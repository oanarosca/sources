var
  fi, fo : text;
  k, h, n, i, prime, d, b, e : integer;
  a : array [1..10] of integer;
  c : array [1..1000] of integer;
  prim : boolean;
begin
  assign (fi, 'printesa.in'); reset (fi);
  assign (fo, 'printesa.out'); rewrite (fo);
  readln (fi, k); readln (fi, h);
  for i := 1 to h do
    readln (fi, a[i]);
  i := 2;
  repeat
    prim := true; b := 0;
    for d := 2 to trunc(sqrt(i)) do
      if i mod d = 0 then
        prim := false;
    if prim = true then
      begin
        for n := 1 to h do
          if a[n] = i then
            inc (b);
        if b = 0 then
          begin
            c[i] := i;
            inc (prime);
          end;
      end;
    inc (i);
  until prime = k;
  for i := c[i-1] downto 2 do
    if c[i] <> 0 then
      write (fo, c[i], ' ');
  close (fi); close (fo);
end.
