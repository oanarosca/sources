var
  fi, fo : text;
  a, b : longint;
  c : shortint;

function sc (n : longint) : integer;
var
  vsc : integer;
begin
  repeat
    vsc := 0;
    repeat
      vsc := vsc+n mod 10;
      n := n div 10;
    until n = 0;
    n := vsc;
  until vsc <= 9;
  sc := vsc;
end;

begin
  assign (fi, 'control1.in'); reset (fi);
  assign (fo, 'control1.out'); rewrite (fo);
  read (fi, a, b, c);
  while sc (a) < c do
    inc (a);
  while sc (b) > c do
    dec (b);
  if (b < a) and (a-b < c) then
    write (fo, 0)
  else
    write (fo, (b-a) div 9+1);
  close (fi); close (fo);
end.
