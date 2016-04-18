var
  fi, fo : text;
  n, i, j, nrp, fri, cifd, imax, maxd, min, m0 : longint;
  a, b, c, cifre : array [1..15000] of longint;
  f : array [0..9] of integer;
  palindrom : boolean;
begin
  assign (fi, 'talent.in'); reset (fi);
  assign (fo, 'talent.out'); rewrite (fo);
  readln (fi, n);
  for i := 1 to n do
    begin
      readln (fi, a[i]); b[i] := a[i];
      for j := 0 to 9 do
        f[j] := 0;
      repeat
        c[i] := b[i] mod 10;
        b[i] := b[i] div 10;
        inc (f[c[i]]); inc (cifre[i]);
      until b[i] = 0;
      cifd := 0;
      for j := 0 to 9 do
        if f[j] <> 0 then
          inc (cifd);
      palindrom := true;
      if cifre[i] mod 2 = 0 then
        for j := 0 to 9 do
          if f[j] mod 2 = 1 then
            palindrom := false
          else
      else // numar impar de cifre
        begin
          fri := 0;
          for j := 0 to 9 do
            if f[j] mod 2 = 1 then
              inc (fri);
          if (fri >= 2) and (cifd >= 2) then
            palindrom := false;
          m0 := 0; // cifre > 0
          for j := 1 to 9 do
            inc(m0, f[j]);
          if (m0 = 1) and (f[0] >= 1) then // o singura cifra mai mare decat 0 si exista 0-uri
            palindrom := false;
        end;
      if palindrom then
        begin
          inc (nrp);
          if cifd > maxd then
            begin
              maxd := cifd;
              imax := i;
              min := a[i];
            end
          else
            if cifd = maxd then
              if a[i] < a[imax] then
                begin
                  min := a[i]; imax := i;
                end;
        end;
    end;
  write (fo, nrp, ' ', min);
  close (fi); close (fo);
end.
