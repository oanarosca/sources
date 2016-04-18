const
  max = 60000;
var
  prime : array [2..60000] of boolean;
  fi, fo : text;
  n, i : longint;
Procedure TabelPrime;   {ciurul lui Eratostene}
Var i,j: LongInt;
    Radical: Real;
Begin
  For i := 2 To MAX Do
    Prime[i] := TRUE;   {marcam toate ca fiind prime}
  Radical := Sqrt(MAX); {mergem pana la radical din MAX}
  i := 1;               {plec de la inceputul vectorului}
  While i <= Radical Do {cat timp nu am terminat}
    Begin
      Repeat
        Inc(i)
      Until Prime[i];   {caut primul numar prim}
      j := i * i;       {primul numar care nu mai este prim este patratul lui}
      While j <= MAX Do {apoi plecand de la el}
        Begin
          Prime[j] := FALSE; {il marchez ca fiind neprim (este multiplu de i)}
          j := j + i         {si merg din i in i si marchez}
        End;
    End;                {while i <= radical}
End;                    {Tabel Prime}

Function Descompune(N, d: LongInt): LongInt;
Var s: LongInt;
Begin
  s := 0;               {initializez contorul cu 0}
  While N>=d Do         {cat timp d mai poate sa apara}
    Begin
      s := s + N DIV d; {d apare de N DIV d ori, le numar}
      N := N DIV d      {elimin aceste aparitii}
    End;
  Descompune := s
End;

begin
  assign (fi, 'factori.in'); reset (fi);
  assign (fo, 'factori.out'); rewrite (fo);
  tabelprime;
  readln (fi, n);
  repeat
    for i := 2 to n do             {determin pe rand celelalte numere prime <= N}
      if prime[i] then
        write(fo, descompune(N,i), ' '); {afisez un spatiu apoi numarul de }
    writeln(fo);             {aparitii a acestuia in factorial}
    readln (fi, n);
  until n = 0;
  close (fi); close (fo);
end.
