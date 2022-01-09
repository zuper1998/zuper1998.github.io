## Firmware Security
+ Miért fontos?
  + Firmware hamarabb betölt mind bármi más -> semmit nem ér az AV és más megoldás

### UEFI boot process -- SEC
+ Első kód amit a cpu futtat
  + minimális kód az SPI flash-ből
  + architektúra dependens
+ SPI Flash stuff
  + cpu-t átirányítja a platform inicializáló kódhoz
+ Sec fázis felelős
  + platform reset event kezelése: power on wake-up
  + microcode patchelése a cpunak
  + config CPU cache as RAM

### SPI flash content
+ Firmware volumes
  + logikai Firmware eszközök
+ FV_Recovery:
  + boot clockot tartalmaza , ami tartalmaza a SEC és PEI fázis kódokat

### UEFI boot process -- PEI
+ PEI: Pre-EFI initialization
+ PEI modulok segítségével inicializálja a hardvert és memóriát
+ Utolsó PEIM indítja a DXE fázist

### UEFI boot process -- DXE  
+ DXE: Driver execution Environment
+ DXE dispatcher FV_mainből átküldi a DXE és RT driverjeit a fő memóriába
+ DXE felelős:
  + additional Hardware config and init
  + SMM -- System management mode setup
  + Enforcing Secure boot
  + Firmware update signature checking

### UEFI boot process -- BDS
+ BDS: bood device selection
+ megnézi a configot hogy honnan kell betőlteni az OS-t
+ ha UEFI secure boot be van kapcsolva akkor az OS bootloader integritását is megnézi

### UEFI boot process -- TSL és RT
+ TSL: Transient system load
+ itt tőlti be az OS bootloaderjét a HDD-ről
+ OS bootloader betőlti az OS kernelt a memóriába
+ Használhat még bootservice kategóriáju dolgokat

### UEFI secure boot
+ Ötlet: ellenőrizni a UEFI boot során futó alkalmazásokat hash és digitális aláírás alapján
+ Nehézség:
  + a secure boot opcionális
  + a security az mentet kulcsokon és hasheken alapúl
  + A flash alapú részei az UEFI-nek SEC, PEI, DXE code nincsenek ellenőrizve

### UEFI secure boot -- Adatbázisok
+ db-ben található a digitális bizonyítványok és image hash-ek
+ dbx-ben ugyan ez csak blacklist formátumban
+ db-t a gyárban kell inicializálni

### UEFI secure boot -- Kulcsok
+ PK -- platform key
  + OEM által beállítva a gyárban
  + KEK illegális modosítását gátolja
  + frissíthető secure flash update-vel

+ KEK: Key exchange Key
  + secure boot adatbázisok védelme
  + Több KEK is lehet
  + KEK segítségével lehet frissíteni az adatbázisokat

### Intel boot guard:
+ Verifikálja a PEI-t
+ Ami Verifikálja DXE/UEFIT
+ Amit pedig az OS loadert

### UEFI Secure Capsule Update
+ a teljes új Firmware alá van írva
+ Az ezt ellenőrző kódot tartalmazza a mostani Firmware
+ Bonusz defense: Intel BIos Guard

### Intel Bios Guard
+ izolált környezetben végrehajtja a Verifikációját a firmware-nek  






























.
