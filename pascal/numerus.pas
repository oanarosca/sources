var
  fi, fo : text;
  n, k, i : longint;
begin
  assign (fi, 'numerus.in'); reset (fi);
  assign (fo, 'numerus.out'); rewrite (fo);
  read (fi, k, n);
  if k mod 2 = 0 then
    begin
      write (fo, k*5, ' ', k*5, ' ');
      for i := 1 to 4 do
        write (fo, k*5-i, ' ');
    end
  else
    begin
      for i := 1 to 4 do
        write (fo, (k-1)*5+i, ' ');
      write (fo, k*5, ' ', k*5);
    end;
  writeln (fo);
  if n mod 5 = 0 then
    writeln (fo, n div 5)
  else
    writeln (fo, n div 5+1);
  if n mod 10 = 0 then
    write (fo, 'A B')
  else
    if n mod 5 = 0 then
      write (fo, 'E F')
    else
      case n mod 10 of
        1 : write (fo, 'A');
        2 : write (fo, 'B');
        3 : write (fo, 'C');
        9 : write (fo, 'C');
        4 : write (fo, 'D');
        8 : write (fo, 'D');
        7 : write (fo, 'E');
        6 : write (fo, 'F');
      end;
  close (fi); close (fo);
end.

