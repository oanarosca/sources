var
  fi, fo : text;
  c : char;
  a : array [0..9] of boolean;
  n, i, j : integer;
begin
  assign (fi, 'magic6.in'); reset(fi);
  assign (fo, 'magic6.out'); rewrite (fo);
  readln (fi, n);
  for i := 0 to n-1 do
    begin
      read (fi, c);
      if ('a' <= c) and (c <= 'z') then
        write (fo, upcase(c))
      else
        a[ord(c)-ord('0')] := true;
      read (fi, c);
    end;
  writeln (fo); i := 0;
  repeat
    inc (i);
  until a[i] = true;
  write (fo, i);
  if a[0] = true then
    write (fo, 0);
  for j := i+1 to 9 do
    if a[j] then
      write (fo, j);
  close (fi); close (fo);
end.

0 3 6 8
