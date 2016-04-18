var
	fi, fo : text;
  a, b, c, max, mij, min, r, zile1, zile2 : longint;
begin
	assign (fi, 'mere2.in'); reset (fi);
  assign (fo, 'mere2.out'); rewrite (fo);
  readln (fi, a, b, c);
  if (a+b+c) mod 3 = 0 then
  	begin
      if (a > b) and (a > c) then
        begin
  		    max := a;
          if b > c then
      	    begin
					    mij := b;
							min := c;
            end
          else
            begin
      		    mij := c;
							min := b;
            end;
        end
      else
  	    if (b > a) and (b > c) then
    	    begin
				    max := b;
            if a > c then
        	    begin
          	    mij := a;
								min := c;
              end
            else
        	    begin
          	    mij := c;
								min := a;
              end
          end
        else
    	    begin
				    max := c;
            if a > b then
        	    begin
          	    mij := a;
								min := b;
              end
            else
        	    begin
          	    mij := b;
								min := a;
              end;
          end;
      if mij-min < max-mij then
  	    begin
          while mij <> min do
          	begin
  	          mij := mij-2;
              min := min-1;
              max := max-3;
              inc(zile1);
            end;
          while max <> mij do
          	begin
  	          zile2 := zile2+2;
              max := max-6;
              mij := mij-3;
              min := min-3;
            end;
          writeln (fo, zile1+zile2);
          write (fo, a-min, ' ', b-mij, ' ', c-max);
        end
      else
  	    begin
    	    while mij <> max do
          	begin
      	      inc(zile1);
              min := min-1;
              mij := mij-2;
              max := max-3;
          	end;
          while max <> min do
          	begin
      	      zile2 := zile2+2;
              max := max-5;
              mij := mij-5;
              min := min-2;
            end;
          writeln (fo, zile1+zile2);
          write (fo, a-max, ' ', b-mij, ' ', c-min);
        end;
  	end
  else
    begin
  		writeln (fo, '-1');
      write (fo, '-1 -1 -1');
    end;
  close (fi); close (fo);
end.
