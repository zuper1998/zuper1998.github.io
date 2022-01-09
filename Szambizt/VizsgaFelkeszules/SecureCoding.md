## Secure Coding Guidlines:s


### CVE -- common vulnerability and Exposures
+ adatbázis az összes ismert sérülékenységről
+ 1-2 óránként új sérülékenység

### Biztonság -- Security

Régi programozási paradigmák nem tartalmaztak biztonságos fejlesztési technikákat emiatt


### Biztonságos szoftverfejlesztési megoldások
Két opció:
**Teljesen át kell szervezni a fejlesztési procedúrát:**
+ OWASP CLASP
+ Microsoft SDL
+ Software Security touchpoints

**Integrálni kell valamelyik érettségi modellt:**
+ OpenSAMM
+ BSIMM
+ SAFEcode

### Új vonatkozások
+ Governance
+ Requirements -- Threat modelling
+ Design -- UMLsec
+ Implementation -- secure coding standards
+ Verification
+ Deployment
+ Operation


### Threat modelling
+ Rizikók és veszélyek feltérképezése
+ Mi az ami értékes számunkra/támadó számára
+ Veszteség támadás esetén és annak minimalizálása

### Terminológia
+ Asset: minden aminek értéke van
+ Threat: egy esemény ami kárt okoz a szervezetben
+ Risk: mekkora esélyel fogja az adott threat károsítani a céget
+ vulnerability: kihasználható sérülékenység

### Threat, Risk, Vulnerability Analysis
+ különböző védelmi megoldások indoklása
+ mennyire nyitott egy támadásra a rendszer
+ ha a rendszer változik újra kell csinálni

### Threat, Risk, Vulnerability Analysis lépései
+ Az értékelés célpontját definiálni kell
  + rendszer biztonsági szintjei között hol vannak a határok, pl Szerver és Applikáció nem ugyan az a szint
  + A rendszer könnyen azonosítható elemekből áll
+ Biztonsági követelmények azonosítása
  + CIA+3A segítségével
    + **C**onfidentiality -- nem nézheti olyan az adatokat aki arra nem jostle
    + **I**ntegrity -- az adatok nem módosíthatóak anélkül hogy az látható legyen
    + **A**vailability -- a rendszer elérhető
    + **A**uthentication -- az entitás az bizonyítani tudja kilétét
    + **A**uthorization -- az entitás csak a számára engedélyezett műveleteket tudja végrehajtani
    + **A**uditing -- minden végrehajtott művelet visszakövethető
  + a biztonsági követelmények rendszer specifikusak
  + a követelményekben pontosítani kell hogy a CIA+3A melyik részére vonatkozik
+ Threat assessment
  + mit ki mivel tudd támadni
  + hogyan nem szabad a rendszert használni
+ Rizikók felbecsülése
  + STRIDE framework segítésével
  + Mekkora esésjel történik meg és mekkora kárt tudd okozni
+ Countermeasure-k azonosítása
  + új asset a rendszerhez amit azért adunk hozzá hogy csökkentsük a rizikót

### STRIDE
+ Spoofing: megszemélyesítés -- confidentiality megsértése
+ Tampering: meg nem engedett módosítás -- integrity megsértése  
+ Repudiation: tevékenység letagadása -- auditing megsértése
+ Information disclosure: olyan info megsértése amihez nincs jogunk -- Authorization/confidentiality megsértése
+ Denial of service: dos/ddos -- avaliablity ellen
+ Elevation of privilege: Authorization ellen  


### Secure design principles
+ Economy of mechanism (KISS) -- keep is simple small
+ Fail-safe defaults -- utolsó jó állapotba visszatérni
+ Complete mediation -- semmit nem hiszünk el, mindenre kérünk biztosítékot
+ Separation of privilege -- modulárisan és robusztusan
+ Least privilege -- minden hol a bare minimum
+ Open design -- NE legyen security by obscurity
+ Least common mechanism -- minél többen használják annál több hiba ismert
+ Psychological acceptability -- vigyázni emberre


### UMLsec
+ uml kiterjesztés biztonsági információkkal
+ új labelek:
+ critical
    + secrecy -- titkos valami
    + integrity -- a jó értékeket nem szabad elronatni
    + high -- az információs csatorna csak más high elemek által befolyásolható
+ Data security
  + az adatok a lehetséges támadókra felkészülten való tárolása
  + egy field: adversary


### CWE -- Common weakness enumeration
+ community által fenntartott lista különböző általános biztonsági hibákról
+ hierarchikusan vannak tárolva ID alapján

### Secure coding standards
+ coding best practices hogy ne legyen biztonsági rés a kódunkban

### Data processing
**IN**
+ Normalization -- átalakítás a "számított" formátumra
+ Filtering -- nem oda való dolgok kiszűrése
+ validation  -- a bemeneti adatok észerűek-e? (nem a jövőben született valaki)

**OUT**
+ Neutralization -- a kimenet se legyen malicious
  + escaping -- a kimenet ne tartalmazzon veszélyes dolgokat


### Concurrency Attack
+ timing window alapú
+ Time-To-Check vs Time-Of-Usage TOCTOU
+ pl mire használ egy fájl változót az máshova mutat

### Reflection based attack
+ az app tudja magát modosítani sort of
+ sok helyen kell speciális engedély pl `java.lang.reflect.ReflectPermission`











































.
