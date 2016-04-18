var
  fi, fo : text;
  i, c, minut, ora, ci : shortint;
  a, b, min, mincal : integer;
  x, y : array [0..9] of integer;
  ore, cal, cifre : array [1..10] of integer;
begin
  assign (fi, 'taste.in'); reset (fi);
  assign (fo, 'taste.out'); rewrite (fo);
  for i := 0 to 9 do
    readln (fi, x[i], y[i]);
  read (fi, a); b := a;
  minut := a mod 100;
  ora := a div 100;
  i := 1; ore[i] := a;
  repeat
    inc (i);
    ore[i] := ore[i-1]+2400;
  until ore[i]+2400 >= 10000;
  inc (i); ore[i] := a+60;
  repeat
    inc (i);
    ore[i] := ore[i-1]+2400;
  until ore[i]+2400 >= 10000;
  ci := i;
  for i := 1 to ci do
    begin
      b := ore[i];
      ora := b div 100;
      minut := b mod 100;
      repeat
        b := b div 10;
        inc (cifre[i]);
      until b = 0;
      cal[i] := cal[i]+(abs(x[ora div 10]-x[ora mod 10])+abs(y[ora div 10]-y[ora mod 10]));
      cal[i] := cal[i]+(abs(x[ora mod 10]-x[minut div 10])+abs(y[ora mod 10]-y[minut div 10]));
      cal[i] := cal[i]+(abs(x[minut div 10]-x[minut mod 10])+abs(y[minut div 10]-y[minut mod 10]));
    end;
  if a = 0 then
    begin
      writeln (fo, 0);
      write (fo, '0000');
    end
  else
    begin
      min := 5000;
      for i := 1 to ci do
        if cal[i] < min then
          begin
            min := cal[i];
            mincal := ore[i];
          end;
      writeln (fo, min);
      write (fo, mincal);
    end;
  close (fi); close (fo);
end.
