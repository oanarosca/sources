var
	fi, fo : text;
  i, n, p, h, s, max, na, maxpd, pd : integer;
begin
	assign (fi, 'domino1.in'); reset (fi);
  assign (fo, 'domino1.out'); rewrite (fo);
  readln (fi, n);
  readln (fi, p, h);
  na := 1; max := p+h; maxpd := 1; pd := 1;
  for i := 2 to n do
  	begin
    	readln (fi, p, h);
      s := p+h;
      if p <= max then
        begin
          inc(pd);
          if pd > maxpd then
        	  maxpd := pd;
				  if max < s then
        	  max := s
        else
        end
      else { p > max }
        begin
        	inc (na);
        	max := s;
          pd := 1;
      	end;
    end;
  writeln (fo, na, ' ', maxpd);
	close (fi); close (fo);
end.
