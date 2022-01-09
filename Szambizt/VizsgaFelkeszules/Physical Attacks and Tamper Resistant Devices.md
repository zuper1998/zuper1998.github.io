## Physical Attacks and Tamper Resistant Devices


### Mi az hogy Tamper Resistant Device?
+ olyan eszközök amikből még úgy sem lehet a védett információt kiszedni hogy ahoz fizikai hozzáférésünk van
+ pl: TPM chipm, Hardware security modules
+ Fő feature-ök:
  + limited and well controlled interfaces
  + erős access control
  + passzív és vagy Aktív tamper prevention/detection

### Use case -- Public Key infrastruktúra
+ a privát kulcsokat meg kell védeni
+ Usereke privát kulcsait álltalában okos kártyákon tartják
+ A CA-ek privát kulcsait Hardware security module-okban tartják melyeken nagyon szigorú védelmi policyket tartattnak be

### Use case -- ATM
+ A pin kód és a kártyából származó kódot távol kell tartani mindenkitől

### Use case -- Automated Fare Collection
+ mint ami van angliában
+ az elektronikus jegyeket validálni kell utközben pl fel és leszállás
+ A validáció a ticket ID és a járművön lévő master key  alapján tőrténik
+ Az említett key-t offline tároljuk ezért meg kell védeniu


### Támadások fajtái
+ Invazív
  + a chipbe belenyúlunk
+ semi invazív
  + a chip felületét izéljük
  + a chip müködőképes marad
+ Noninvasive
  + semmi fizikai behatolás
  + Local:
    + a chip és a környezete közötti interakció manipulálása és megfigyelése
  + remote:
    + API támadások


### Invazív támadás
+ első lépés: a chip belsejéhez való hozzáférés
  + integrált áramkörök esetén savval maratjuk le az epoxi gyantát
+ második lépés: probing chips internally
  + chipből kiolvassuk az adatokat
  + kell hozzá:
    + mikroszkóp
    + alacsony vibrációju platform
    + micromanipulátor
    + lézer


### Védekezés invazív támadások ellen
+ egy sensor háló ami ha megszakad a chip tőrli a szenzitív infót
+ nehezebbé tenni a reverse engineeringet
  + régebben a felületről leolvasható volt hogyan mentek az alacsonyabb rétegeken belűl a logikai vonalak
  + most már csak a legfelsőt tudjuk olvasni az alacsonyabb szintűekhez le kell maratni a felső réteget
  + ez úgy lett megoldva hogy minden réteget lesimitanak mielött a következőt rárakják, így nem lehet a domborzatból kiolvasni

### Semi invasive attack
+ no penetration ( ͡° ͜ʖ ͡°)
+ pl UV fényel reseteli a microcontrollerek védő rendszerét -> ki lehetet olvani a tartalmukat
+ optikai probingal bármmilyen bitet át lehet billenteni az SRAM-ban
+ Védekezés:
  + Detection és key erasure
  + nem átlátszó top layer


### Local Noninvasive attack
+ side channel attack
+ timing alapú támadás: mennyi ideig tart valamit csinálnia
+ power Analízis a felhasznált energiában létrejövő növekedést figyeljük
  + mikor nehezebb műveletet végez több energiát fogyaszt
+ Extrém környezetekben nem elvártan viselkedik az eszköz


### Defending against Side channel attack
+ a timing és energia felhasználás minden futási ágon legyen egyenlő
+ időben konstans műveletek használata -- ne függjenek az inputtól
+ legyen az input randomizálva hogy a kiszedhető adat felismerhetetlen legyen

### FIPS 140-2 Security levels
+ crypto modulok biztonsági elvárásait adja meg a szabvány
+ Level 1:
  + nincs szükség fizikai védelemre
  + cripto könyvtár
+ Level 2:
  + szükség van szabotázst jelző burkolásra  
  + olcsó mikrokontrollerek
+ Level 3:
  + szükség van szabotázst védő fizikai védelemre
  + TPM
+ Level 4:
  + aktív szabotázs védelem és érzékelés
  + behatolás esetén minden fontos adatot töröl



### Classes of tamper resistant devices
+ High end
  + IBM 4758 coprocessor
  + tamper sensing mesh
  + active detection of tampering --> erases everything
+ low end
  + olcsó mikrokontrollerek
  + csak szimmetrikus kriptográfiára jó
  + nem áll ellen támadásnak
+ mid range  
  + TPM chip
  + Egy chipes eszközök amik hardenelve lettek támadások ellen


### IBM 4758 coprocessor
+ programozható PCI board magas szintű tamper ressistant csomagolásban
+ Védelme:
  + egy vezetőkből álló hálózat borítja melyhez hozzá van kötve egy áramkőr ami érzékeli a benne fellépő változást
    + A vezetők nem fémből vannak és nagyban hasonlítanak a körülöttük lévő anyagra
    + több rétegből áll a hálózat
  + A Rendszer le van zárva és földelve
  + Érzékeli a következők változását:
    + hőmérséklet
    + páratartalom
    + nyomás
    + ionizáló sugárzás
    + táp áramérőség és processzor sebessége
+ Bármi illegális hozzáférést érzékel -> BBRAM törlése és reset
+ FIPS 140-2

### Smart card security measueres
+ felső szint vezető álló hálózat
+ randomizált logikai design
+ belső BUS harveres szinten kriptálva
+ fény szenzor
+ Áramorrőség változás érzékelők
+ processzor sebesség érzékelők
+ csak akkor érzékel ha van tápfeszültség

### API támadások
+ API -- amin keresztül a külvilággal kommunikál az eszköz
+ API támadás esetén a rendszer gyengeségeit próbáljuk majd kihasználni
+ Cél: secret kiszedése az eszközből
+ Első példa:
  + a kitalálni akart kulcsal exportélunk a master key-el kódolt KEK-et (Key Encryption Key)
  + a kapott eredményt a decrypt függvénybe rakjuk mint dekriptálni akart üzenet, ahol a decrypt-hez a kulcs a master key-el kódolt KEK
  + a kapott érték a K kulcs lesz


### The API of the IBM 4758
+ A kulcsok key token-ben vannak tárolva
+ A key token a master key segítségével vannak kódolva
+ vagy egy wraping key-t modulálunk a tokenben található kulcs fajtájával, ahol a kulcsok tipusai kontroll vektorokba vannak kódolva

### API támadás az IBM 4758 ellen
+ key part import segítségével két ismeretlen de összefüggő kulcsot hozzunk létre legyenek ezek UKEK és UKEK'
+ key_import segítségével hozzunk létre két  identikus másolatot az ismeretlen URK kulcsról de mást típussal
+ Az így létrehozott másolatok segítségévelki tudjuk exportálni az eredeti URK kulcsot majd dekriptálni is tudjuk
+ Ez 3 oldalnyi key shitposting ha egyáltalán kérik szóbelin az már szimpla köcsögség ennél részletesebben nem vagyok hajlandó leírni    


### Pin generálás
+ IN:
  + PAN -- personal account number
  + hex to dec tábla
  + Pin generáló kulcs vagy token
+ Lépések
  + encrypt pan with pin
  + decimállá alakítani az outputot
  + X digitet megtartasz ez lesz a PIN

### PIN verifikálás
+ IN
  + PAN
  + hex to dec tábla
  + kriptált PIN blokk
  + PIN encryption key
  + PIN generation key
+ Lépések:
  + PIN kiszámolása a PAN, PIN gen key és hextodec táblából
  + PIN dekriptálása a pin encryption key segítségével
  + A két PIN összehasonlítása

### PIN offset generálás
+ Saját kód
+ IN:
  + PAN -- personal account number
  + hex to dec tábla
  + Pin generáló kulcs vagy token
  + user selected PIN UPIN
+ Lépések
  + PIN létrehozása
  + OFFSET := UPIN - PIN mod 10
+ Out
  + OFFSET értéke a user kártyáján tárolva


### PIN ellenőrzés offszettel
+ IN
  + PAN
  + hex to dec tábla
  + kriptált PIN blokk
  + Offset
  + PIN encryption key
  + PIN generation key
+ Lépések:
  + PIN kiszámolása a PAN, PIN gen key és hextodec táblából
  + UPIN kiszámolása PIN és OFFSET-ből
  + UPIN2 kiszámolása a PIN blokkból és pin encryption key-ből
  + két UPIN összehasonlítása

### Decimalization attack
+ a dectoHex tábla modosításával
+ megváltoztatjuk x-et és kiprobáljuk a kriptált pint-t
+ ha x része a pinnek akkor fail ha nem akkor siker

### Api támadások elleni védekezés
+ formális Analízissel leeht tesztelni az üzenetekre
+ nehéz mert nagyon sok kombináció létezik
+ meg kell határozni rossz állapotokat




.
