var
  fi, fo : text;
  a, b : longint;
  c, i, suma, cifrea, cifreb, aux : shortint;
  f, f1 : array [0..9] of integer;
  cif : array [1..18] of integer;
  ordonat : boolean;
begin
  assign (fi, 'cifre3.in'); reset (fi);
  assign (fo, 'cifre3.out'); rewrite (fo);
  read (fi, a, b);
  repeat
    c := a mod 10;
    a := a div 10;
    inc (f[c]);
  until a = 0;
  repeat
    c := b mod 10;
    b := b div 10;
    inc (f1[c]);
  until b = 0;
  for i := 0 to 9 do
    suma := suma+f[i]*f1[i];
  if suma = 0 then
    write (fo)
  else
    for i := 0 to 9 do
      if (f[i] <> 0) and (f1[i] <> 0) then
        write (fo, i, ' ');
  writeln (fo); close (fi); reset (fi);
  read (fi, a, b); i := 1;
  repeat
    cif[i] := a mod 10;
    a := a div 10;
    inc (i); inc (cifrea);
  until a = 0;
  repeat
    cif[i] := b mod 10;
    b := b div 10;
    inc (i); inc (cifreb);
  until b = 0;
  repeat
    ordonat := true;
    for i := 1 to cifrea+cifreb-1 do
      if cif[i] > cif[i+1] then
        begin
          aux := cif[i]; cif[i] := cif[i+1]; cif[i+1] := aux; ordonat := false;
        end;
  until ordonat;
  for i := cifrea+cifreb downto 1 do
    write (fo, cif[i]);
  close (fi); close (fo);
end.
