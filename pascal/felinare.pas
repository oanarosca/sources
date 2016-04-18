var
	a : array [0..5000] of shortint;
  n, i, j, operatii, aprinse : longint;
  fi, fo : text;
begin
	assign (fi, 'felinare.in'); reset (fi);
  assign (fo, 'felinare.out'); rewrite (fo);
  read (fi, n);
  aprinse := n;
  for j := 0 to n-1 do
  	a[j] := 1;
  repeat
  	inc(operatii);
    if i = 0 then
      if a[n-1] = 1 then
				if a[i] = 1 then   								 	 {AA - bine: stinge }
          begin                              {AF - bine: aprinde}
          	a[i] := 0;                     	 {FA -              }
            aprinse := aprinse-1;          	 {FF                }
          end
        else
          begin
            a[i] := 1;
            inc(aprinse);
          end
    	else
    else
  	  if a[i-1] = 1 then
				if a[i] = 1 then
          begin
      	    a[i] := 0;
            aprinse := aprinse-1;
          end
      	else
          begin
            a[i] := 1;
            inc(aprinse);
          end;
    inc(i);
  	if i = n then
    	i := 0;
  until aprinse = n;
  write (fo, operatii);
  close (fi); close (fo);
end.
