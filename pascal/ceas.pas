var
	fi, fo : text;
  m, h1, h2, h3, m1, m2, m3, mh1, mh2, mac, ms : integer;
  sta : boolean;
begin
	assign (fi, 'ceas.in'); reset (fi);
  assign (fo, 'ceas.out'); rewrite (fo);
  read (fi, h1, m1, h2, m2);
  if h1 = 12 then
  	h1 := 0;
  mh1 := h1*60+m1;
  mh2 := h2*60+m2;
  mac := mh1; { minute aratate de ceas }
  if mac mod 65 = 0 then
  	sta := true
  else
  	sta := false;
  for m := 1 to mh2 do
  	begin
      if sta then
      	begin
        	inc (ms);
          if ms = 5 then
          	begin
          		sta := false; ms := 0;
            end
        end
      else
      	begin
      	  inc (mac);
      	  if mac mod 65 = 0 then
      			sta := true;
				end
    end;
  h3 := mac div 60; h3 := h3 mod 12;
  if h3 = 0 then
  	h3 := 12;
  m3 := mac mod 60;
  write (fo, h3, ' ', m3);
  close (fi); close (fo);
end.

 1  5   =>   60 +  5 = 65
 2 10   =>  120 + 10 = 130
 3 15   =>  180 + 15 = 195
 4 20   =>  240 + 20 = 260
 5 25   =>  300 + 25 = 325
 6 30   =>  360 + 30 = 390
 7 35   =>  420 + 35 = 455
 8 40   =>  480 + 40 = 520
 9 45   =>  540 + 45 = 585
10 50   =>  600 + 50 = 650
11 55   =>  660 + 55 = 715
12 60   =>  720 + 60 = 780
