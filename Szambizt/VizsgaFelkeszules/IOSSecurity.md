### iOS Security
+ miért nem hívjuk úgy hogy "jos"?



### System Security - Secure boot
+ Cél:
  + szoftveres komponensek integritása
  + csak akkor lép tovább ha a teljes chain of trust-ot ellenőrzi
    + csak apple eszközökön megy
    + ebbe bele tartozik a kernel boot loader, kernel kiterjesztések etc
+ Secure enclave processzor
  + külön elzárt secure boot
  + Boot Progress Register segítségével
+ Ha van mobilhálózati elérés akkor a hozzá tartozó modull is hasonló módon indul el
+ Secure boot chain
  + Boot ROM:
    + read only
    + root of trust for hardware
  + iBoot
  + iOS kernel
+ IF load fails:
  + boot rom közben -> DFU mode
  + a következő szint ellenőrzése közben --> Recovery mode

### System Security - Update
+ downgrade prevention
+ iOS update esetén az eszköz csatlakozik az apple installation authorization szerverhez és a következőket küldi át
  + kriptográfiai mérések különböző elemeiről
  + randomizált anti replay value
  + az eszköz egyedi ECID -- Exclusive chip identification
+ A szerver megmondja mely frissítéshez férhet hozzá

### System Security - Secure Enclave
+ security coprocessor
+ system on a chip-en van
+ Encrypted memory
+ hardveres szintű random number generator
+ kriptográfiai funkciók adatvédelmi kulcsmenedzsmenthez
+ Felelős még a fingerprint feldolgozásáéért ami a TOuch és Face ID-ból származik
+ Secure Enclave OS
  + custom apple mikrokernel
+ Secure enclave boot rom


### System Security – Low Level protections
+ Kernel integrity protection
  + Kernel inicializálás után kapőcsolódik be és megakadályozza a kernelen végzett modosításokat
  + Boot után a memory controller nem engedélyezi az írást a védett memória területeken
+ System coprocessor integrity protection
  + Kernel Integrity protectionhöz hasonló
+ Pointer authentication codes
  + memory corruption támadások ellen
  + function pointer és return address nem változhat

### System Security
+ Touch ID
  + erősebb jelszavakat lehet így használni
  + random match esélye 1:50000
+ Face ID
  + erősebb jelszavakat lehet így használni
  + random match esélye 1:1 000 000

### Face ID
+ confirms attention  -- kamerába nézel e
+ Ellenőrzi:
  + mélységet
  + infrared képet
+ A mélységet adó képsorozatot a truedepth kamera randomizálja
+ A12-es Bionic processors neural engine
  + transform data to math representation
  + össszehasonlítja a tárolt adattal


### Data protection
+ AES 256 engine
+ kulcs UID ami a bele van égetve az eszközbe nem érhető el semmilyen módon
+ minden adat az eszközhöz tartozik, kicseréled a chipet nem fogod tudni elolvasni
+ Secure enclave
  + true random generator
  + multiple ring osclilators
+ Minden crypto modul: FIPS 140-2 level 1

### File Data protection
+ kulcs hierarchiával
+ minden filera külön 256bit AES kulcs
+ külön File rendszer kulcs -- iOS installnál

### Data protection classes
+ Teljes
+ Míg ki nem nyitják
+ Első user auth
+ nincs

### Passcode
+ ha user beállítja automatikus a DATA protection
+ bonusz entropia a pár kulcs számára
+ összefonódtatva a UID-vel
+ minden probálkozás 80ms
+ Secure enclave még ujraindítások között is biztosítja a timert

### Express cards with power reserve
+ ha van elég áram még benne engedi a transit kártyák használatát


### Network security
+ TLS
+ APP onkénti VPN, mindig ON
+ Randomizált MAC amikor wifit keres

### App security
+ aláírott és verifikált sandbox
+ minden futatható fájlt alá kell irni az Apple álltal kiállított certificate-el
+ Runtime security  
  + third party appok sandbox
  + OS nagy része read only
  + nagy része az OS-nek és minden third party app non-privileged userként fut
  + Execute Never XN protection
  + custom keyboard:
    + egész rendszerre kivéve passcode, secure text
    + restricted sandbox: nincs hálózati elérése
























.
