strcpy hossz ellenőrzés nélkül másol


authenticate felépítése:
params -- char * -- 4 byte
ret address -- 4 byte
sEBP -- 4 byte
locals  --    const char *  és  authentication -- 4 + 8 + 8 byte


### gdb debuggerrel memória elemzés
break 21 -- break point 21. sor
set args
`x/16x $esp ` -- 16 byte kiírása az esp regisztertől kezdődően
Jobbról balra kell olvasni a byte-okat asciiként


### Támadás
sérülékeny második strcpy-t támadjuk
return addresst felülírjuk
azt hogy mire a bináris elemzésével ki lehet találni -- itt gdb-vel
disas parancs -- c kód + assembly kód
Access granted sor első címe -- de meg kell változtatni a bytonként a sorrendjét, és bytera konvertálni őket $'\x51'

### Védelmek bekapcsolása

#### Stack smashing protection
+ detektálta a stack smashinget
+ látható a canary , és a fv param másolata


#### NX védelem
+ a támadás működik
+ nem meglepő :D













.
