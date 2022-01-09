## Trusted Computing

### Mi a Trusted Computing
+ olyan technologia ami hardveres támogatást használ hogy a komputer konzisztensen úgy viselkedjen ahogy kell neki
+ Ez lehet:
  + tamper resistant modules
  + hardveres security mechanisms
+ Ennek segítségével megoldható hogy egy malware még magas jogosultságokkal sem tudja majd a rendszer fölött teljesen átvenni az irányítást
+ pl a TPM -- Trusted platform module

### TPM BASED TRUSTED COMPUTING
+ A TPM segítségével a teljes platform:
  + autentikálhatja magát
  + autentikálhatja a konfikurációját
+ A fő motiváció a TC mögött a DRM volt
  + nem hackelt lejátszón halgatod az illegálisan letöltött számot ...
  + cringe

### Trusted Computing Group
+ vendor neutral hardware based root of trust
+ fő "gyártámnya" a TPM specifikáció

### Roots of trust provided by TPM

+ Root of trust for measurment
  + hash algoritmus ami segítségével report készíthető a gép konfigurációjáról és állapotáról amit külsőleg ellenőrízni is lehet hogy igazi

+ Root of trust for storage
  + védet hely a titkos kulcsok számára
  + HDD titkosítás
+ Root of trust for reporting
  + platform indentifikálásához

### TPM authdata
+ minden TPM objektum társítva van egy authdaa objektumhoz
+ lehet gyenge könnyen kitalálható secret
+ minden user process ami használni akar egy TPM objektumot kell bizonyítsa hogy ismeri ezt a secretet

### TPM kulcsok
+ fába vannak rendezve
+ SRK -- Storage root key
  + TPM-ben van tárolva
+ Child keys
  + új kulcs létehozása a TPM_CreateWrapKey-el
    + ehez kell egy a fában lévő kulcs aminek ez lesz a gyereke
    + a visszakapott blop két részből áll
      + a kulcs publikus része
      + a kulcs privát része kódolva a szülőjével

### Secure storage
+ TPM_Seal segítségével kódoljuk le a az adatot
+ TPM_LoadKey2 segítségével töltjük be a kulcsot a kriptált blob-ból



### platform measurement
+ Egy komponens mérése == a hash-jének kiszámolása
+ Egy komponens megmérhet egy másikat és az eredményt belerakja a PCR -- Platform configuration Register-be
+ PCR-ekbe egymás utáni méréseket belerakhatunk extend segítségével

### measured boot
+ A minden elem betőlti a következőt majd megméri és egy PCR-be rakja, késöbb extend már

### Attestation and access control
+ Attestation
  + állapot bizonyítása az összes állapotot gyüjtő PCR aláírt verziójának elküldésével
+ Access control
  + PCR segítségével elérhető hogy csak az arra engedélyezett szoftver érheti el az adatot


## ARM trustzone

### Principles
+ minden hardveres chip úgy van létrehozva hogy két világban éljenek
  + Secure world: a biztonsági alrendszerhez
  + Normal world: minden másnak
+ egy CPU mag képes mindkét világból kódot végrehajtani
+ így gyorsan lehet security operációikat végrehajtani
+ Hardver logikának köszönhetően -- TrustZOne-enabled 0 vagy 1  -- Normál világból nem érhető el a Secure

### System bus operations
+ NS-- nonsecure bit segítségével menedzselve
+ Nonsecure master csak nonsecure slave-t érhet el
+ CPU secure/non-secure master attól függően hogy Secure worldot vagy Normált futtat

### Trusted execution Environment -- TEE
+ TEE: izolált futási környezet
  + biztosítja a benne futó alkalmazások integritását és az adataik biztonságát
  + fő processzoron van implementálva
  + hardveres izoláció

### Trusted OS
+ Trusted core framework OS szintű funkcionalizást biztosít a Trusted Applikációk számára
+ Trusted Device drivers: kommunikációs interfész a TEE számára
+ Trusted KErnel: OS menedzsment funkciók
+ TEE communication agent: kommunikál a REE communication agentel

### Trusted Applications
+ can start execution only on external command
+ Ha egy kliens alkalmazás létrehoz egy sessiont a trusted appikációval akkor annak egy instance-jával épít fel kapcsolatot

### Intel SGX
+ Intel SGX = intel software guard extensions
+ A fontos dolgokat egy enclavenek nevezett védett konténerben futattja
+ még egy magas privilégimmal futó malware ellen is védelmet add

### Enclave
+ DLL-hez hasolnó
+ saját kód, data
+ enclave el tudja érni az alkalmazásának a memóriáját de nem fordítva
+ SHA256 hash értékkel van indentifikálva a kód és az adat amit kreálásnál kapott
+ signed with 3072 bit RSA key

### Enclave Runtime protection
+ Memóriábajn az intel Memory Encryption Engine -- MEE -- védi
+ Memory controller ha el akarja érni a kriptált memóriát az MEE seamlesly dekódolja
+ A kulcsokat egy a csak MEE számára elérhető RNG-ből származnak
+ Ha nem sikerül a verifikáció
  + MEE eldobja a tranzakciót
  + a memória kontroller le lesz zárva
  + újra kell indítani a gépet
















.
