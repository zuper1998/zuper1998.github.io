### Security Testing

Cél: sérülékenységek megtalálása
+ Pozitív követelmény: ez kell
+ Negatív követelmény: ha ez van az baj

### Tesztelési dimenziók
+ Cél:
  + funkcionális: úgy működik ahogy kéne neki
  + nemfunkcionális: úgy nem-működik ahogy kéne neki

+ Hatáskör:
  + modul
  + Integráció
  + Rendszer

+ Elérhetőség
  + whitebox
  + greybox
  + blackbox

### Tesztelés menete
+ Teszt tervezés: mit, miért, hogyan, milyen funkciókat, mikor
+ Teszt dizájn: tesztelt feltételek és absztrakt osztályok
+ Implementáció: a tesztek megírása
+ Végrehajtás
+ A tesztek eredményeinek értékelése

### Statikus ellenőrzési technikák
+ Statikus analízis
+ Code Review
+ Taint analízis
+ Symbolic execution


### Statikus analízis
+ nincsen semmi futtatva csak szemantikusan ellenőrizve
+ Pro:
  + Skálázhatóbb
  + már a fejlesztés elején is lehet használni
+ Con:
  + Sokszor fals pozitív eredményeket add mert az futás közben nem történhetne meg
+ Lépései
  + Input: szoftver amit tesztelni kell
  + Absztrakt szintaxis fává változtatja
  + A tool végrehajtja az analízist
    + adat dependencia gráf
    + control dependencia gráf
    + Program dependencia gráf
  + Reportolja mit talált

### Code Review
+ hibák és sérülékenységek találása  a kód olvasása által
+ Pro: az ember kreatív sok mindent megtalál
+ Con: nehéz, pepecs rEEEEEEEEE
+ **statikus analízis** segítségével ez gyorsítható: az ember csak a report-okat nézi meg
  + Pro: gyors, nem kell akkora hozzáértés
  + Con: csak azt látjuk amit a tool észre vessz


### Taint analízis
+ irányított gráf a különböző futási blokkok
+ sanitization bizonyos bizonyos helyeken
+ start user input
+ end a sink ami Security sensitive operáció
+ Ötlet: a user adat megjelölése
+ Figyeljük hogy a jelölés eljut e majd a a sinkbe, és ha igen merre ment
+ Nehézségek:
  + undertainting: elveszhet
  + overtainting: az is megváltozik ami nem taintel sourceból jön
  + Tain sanitization: az analízis csak add taintet nem vesz el


### Symbolic execution
+ szimbolikus értékel megy végig
+ minden ág végrehajtódik és nézi hogy milyen feltételek kellenek hogy ott legyen pl. a!=1
+ végén megadja hogy mi kell oda és még példát is add
+ PRO:
  + Automata generálása a teszt bemeneteknek
  + Magas szintű teszt lefedetség
  + Komplex szoftverre is jó
+ CON:
  + erőforrás igényes
  + környezet is bekavarhat
  + megoldhatatlan feltételek
+ Megoldás:
  + érdekes részek szimbolikusan
  + unalmas rész cpu-n


### Dinamikus analízis
+ analízis közben a szoftvert futtatja
+ Pro:
  + pontosabb eredmények
  + a sérülékenységek ténylegesek
+ Con:
  + nem biztos hogy egy programon futtatható -- lehet kell pl debug mode


### Fuzzing
+ random input értékek
+ cél minél mélyebbre jutni

#### Fuzzing fajták
+ alapötlet: addig nyomni a random adatot a programba míg nem hal meg
+ Mutation based fuzzing: egy valid inputot randomra változtatunk
+ Generator based fuzzing: random input egy bizonyos mintát követ
+ Evolutionary fuzzing: optimalizálja hogy minél lejjebb menjen

### Penetration testing

+ Bemenet: egy sort of működő igazi szoftver
+ Lépések:
  + Planning: mi van scopeban, igazi vagy teszt rendszer, mikor szabad csinálni
  + Discovery: felismerni és megtalálni az összes interfészt majd sérülékenységi tesztelés
  + Attack: a sérülékenység kihasználása $\rightarrow$ nagyobb foothold a rendszeren vissza a discovery
  + Reporting: folyamatosan jelenteni és dokementálni mindent


### Formális technikák
+ matematika alapú
+ analízis modell a szoftver komponenseknek
+ PRO:
  + megbízhatóan megtalál sok dolgot
+ CON:
  + nehéz formalizálni a biztonsági követelményeket
  + nagyon sok skill kell hozzá
  + Igazi rendszerek esetén nem biztos a teljes modell létezése


### Formalizmusok:
+ State based notation
+ Functional notation
+ Transition based notation
+ History based notation
+ Operational notation


### State based notation
+ Rendszer: változók és a hozzájuk tartozó operációk
  +  Itt a változók azok a rendszer állapotai
+ Properties: rendszer objektumait korlátozó invariánsok -- cuccok amik nem változnak operációk közben
+ Jobban a fókuszban van a **sequential** végrehajtás


### Functional notation
+ Rendszer: strukturált matematikai funkciók
+ Properties: kondicionális egyenletek
+ könnyen lehet komplex objektumokat definiálni
+ nehéz lekódolni

### Transition based notation
+ Rendszer: lehetséges állapotok és a közöttük való tranzíciók
  + tranzíció: olyan esemény ami irányítja/ráhat a különböző dolgok végrehajtására
+ azt modellezi hogy a rendszer miképp reagál a különböző eseményekre
+ múltba nem tud "nézni"


### History based notation
+ miket csinálhat a rendszer az idő folyásával
+ temporális logikai leírásokkal van megadva az események sorrendje

### Operational notation
+ Rendszer: egy strukturált folyamat lista
+ Elosztott rendszerek leírására van kitalálva
+ konkurens műveletekre tökéletes, API modellezés


### Verifikációs megoldások:
+ Model checking
+ Theorem proving

### Model checking
+ Bejárni a formális modellt
+ Ez valójában szinte lehetetlen a nagyobb kódoknál mert a modell szinte végtelen tipusú inputot tudd kezelni
+ Bounded model checking: csak egy bizonyos mélységig megyünk le


### Theorem proving
+ reasoning alapú
+ szabály alapú
+ végtelen sok állapotú rendszert lehet így ellenőrizni
+ viszont ez sokszor nagyon magas szintű formalizmus redukcióval érhető csak el
















































































  .
