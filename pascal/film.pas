var
  fi, fo : text;
  b, f : integer;
begin
  assign (fi, 'film.in'); reset (fi);
  assign (fo, 'film.out'); rewrite (fo);
  read (fi, f, b);
  if b > f then
    begin
      while b <> f do
        begin
          write (fo, 'bfb');
          b := b-2;
          f := f-1;
        end;
      while b <> 0 do
        begin
          write (fo, 'bf');
          dec(b)
        end;
    end
  else
    begin
      while f <> b do
        begin
          write (fo, 'fbf');
          f := f-2;
          b := b-1;
        end;
      while f <> 0 do
        begin
          write (fo, 'fb');
          dec(f)
        end;
    end;
  {writeln (fo);}
  close (fi); close (fo);
end.

13 8
11 7
 9 6
 7 5
 5 4
 3 3

13 8
12 7
11 6
 6 1
 5
