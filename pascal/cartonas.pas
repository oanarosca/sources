var
	fi, fo : text;
  n, r, x, nr, i, nn, nx, nivel, s, nc1 : longint;
  a, b, n1 : array [1..100] of longint;
begin
	assign (fi, 'cartonas.in'); reset (fi);
  assign (fo, 'cartonas.out'); rewrite (fo);
  readln (fi, n);
  readln (fi, x);
  for i := 1 to n do
  	begin
  		read (fi, a[i]);
      if a[i] = x then
      	nx := 1;
      s := s+a[i];
    end;
  repeat
  	r := s mod 2; s := s div 2; n1[1] := n1[1]+r;
  until s = 0;
  nr := n; nivel := 2;
  for nn := nr downto 2 do
  	begin
      for i := 1 to nn-1 do
      	begin
  	    	b[i] := a[i]+a[i+1];
          if b[i] = x then
          	nx := nivel;
        end;
      for i := 1 to nn-1 do
      	begin
        	a[i] := b[i]; s := s+a[i]
        end;
      repeat
  	    r := s mod 2; s := s div 2; n1[nivel] := n1[nivel]+r;
      until s = 0;
      inc(nivel);
    end;
  writeln (fo, b[i]);
  writeln (fo, nx);
  for nc1 := 32 downto 0 do
    for nivel := 1 to n do
			if n1[nivel] = nc1 then
				write (fo, nivel, ' ');
  close (fi); close (fo);
end.
