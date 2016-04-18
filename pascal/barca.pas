var
	fi, fo : text;
  n, i : longint;
begin
	assign (fi, 'barca.in'); reset (fi);
  assign (fo, 'barca.out'); rewrite (fo);
  read (fi, n);
  writeln (fo, 4*n);
  for i := 1 to n do
  	begin
    	writeln (fo, 'IG');
      writeln (fo, 'I');
      writeln (fo, i);
      writeln (fo, 'G');
    end;
  close (fi); close (fo);
end.
