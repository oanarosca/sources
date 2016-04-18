{ solutie corecta, verificata cu datele de test }

const
	dl : array[0..3] of shortint = (-1, 0, 1, 0); {descrie directiile}
	dc : array[0..3] of shortint = ( 0, 1, 0,-1);
var
	nf : char;
  fi, fo : text;
  p : array[1..50,1..50] of byte; {valorile oualor de pe pajiste}
  l, c, d : array[1..100] of shortint;
  cos : array[1..100] of longint; {valoarea unui cos}
  lo, co, v, n, nip, i : byte;
  max : longint;
  nl, no, o, noc, t : word;
begin
  write('Numarul fisierului : '); read(nf);
  assign (fi, 'oua.in'); reset(fi);
  assign (fo, 'oua.out'); rewrite(fo);
  readln(fi, nl, no); {numarul de linii, numarul de oua}
  for o := 1 to no do
  	begin
  		readln(fi,lo,co,v); {linia, coloana si valoarea unui ou}
      p[lo,co] := v;
    end;
  readln(fi,n); {numarul de iepurasi}
  for i := 1 to n do
  	begin
    	readln(fi,l[i],c[i]);
    	if l[i] = 1 then
        begin
      		d[i] := 2; l[i] := 0;    {va porni spre sud}
        end;
    	if c[i] = nl then
      	begin
      		d[i] := 3; c[i] := nl+1; {va porni spre vest}
        end;
    	if l[i] = nl then
      	begin
      		d[i] := 0; l[i] := nl+1; {va porni spre nord}
        end;
      if c[i] = 1 then
      	begin
      		d[i] := 1; c[i] := 0;    {va porni spre est}
        end;
		end;
  t := 0;   {durata scursa de la inceputul concursului}
  nip := n; {numarul de iepurasi existenti pe pajiste}
  repeat
  	inc(t); {Se scurge un minut};
  	for i := 1 to n do
      if d[i] <> -1 then {Iepurasul i este pe pajiste.}
        begin
        	inc(l[i],dl[d[i]]); {Stabilim noua pozitie a iepurasului.}
          inc(c[i],dc[d[i]]);
          {Iepurasul e pe pajiste ?}
          if (1 <= l[i]) and (l[i] <= nl) and (1 <= c[i]) and (c[i] <= nl) then
            if p[l[i],c[i]] >= 1 then {Exista ou in aceasta pozitie.}
              begin
                inc(cos[i],p[l[i],c[i]]); {Actualizam valoarea cosului iepurasului i.}
                inc(noc);                 {Am mai cules un ou.}
                p[l[i],c[i]] := 0;        {In acel loc nu va mai exista ou.}
                d[i] := (d[i]+1) mod 4;   {noua directie a iepurasului}
              end
            else {Nu exista ou. Nu facem nicio operatie.}
          else
            begin
              d[i] := -1; {Nu ne vom mai ocupa de acest iepuras.}
              dec(nip);   {Avem pe pajiste cu un iepuras mai putin.}
            end;
        end;
  until nip = 0; {nu mai sunt iepurasi pe pajiste}
  max := 0;
  for i := 1 to n do
    if cos[i] > max then
    	max := cos[i];
  write(fo, noc,' ',max,' ',t-1);
  close(fo);
end.

Numerotarea directiilor:
 1
0+2
 3
