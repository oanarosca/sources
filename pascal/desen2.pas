var
	fi, fo : text;
  a, b, m, b2, a2, p : longint;
begin
	assign (fi, 'desen2.in'); reset (fi);
  assign (fo, 'desen2.out'); rewrite (fo);
	read (fi, a, b);
  if a < b then
    begin
  	  m := b;
  	  while m mod a <> 0 do
        m := m+b
    end
  else
    begin
      m := a;
  	  while m mod b <> 0 do
    	  m := m+a;
    end;
  b2 := m div b;
  a2 := m div a;
  p := b2*a2;
  writeln (fo, m);
  write (fo, p);
  close (fi); close (fo);
end.
