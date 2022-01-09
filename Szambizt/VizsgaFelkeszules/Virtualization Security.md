## Virtualization Security


+ kb mindent virtualizálunk
  + hardver, hálózat, tárhely etc
+ Pro:
  + erőforrás használat optimalizálás
  + gyorsabb telepítés
  + flexibility
  + kényelmesebb
+ Con:
  + Security issue

### Fő problémák
+ Complexebb a rendszer --> több bug és vuln
+ Menedzsment össze vissza lehet mert a különböző rendszerek összefonódnak
+ ha a központi virtualizációs rendszert feltörik akkor rip minden


### HARDWARE VIRTUALIZATION SECURITY

#### Def:
+ Hypervizor vagy Virtual machine monitor: a virtuális gépek futtatásáért felelős szoftver  
  + ő felel a határok betartásáért
+ Host -- fizikai gép  
+ Guest OS -- virtuális OS ami fut


### Hypervizor
+ két fajta, privilégiumi szint szerint
  + Type 1 hypervizor: guest OS ring 0, hypervizor ring -1 -- Native
  + Type 2 hypervizor: guest OS ring 3, hypervizor + host operating systemm ring 0 -- Hosted


### HARDWARE VIRTUALIZATION támadások fajtái
+ Interakció szinten való felosztás
  + passzív:
    + hypervizor detektálása
    + hálózat monitorozása
  + Aktív
    + DoS
    + VM escape
    + Hyperjacking
+ Támadás iránya szerint
  + guest-ti-Guest
  + Guest-To-Host

### Hypervizor detektálása
+ Cél: észrevenni hogy a program egy hypervizor-ban azaz virtuális környezetben fut
+ Miért?
  + jobb kompatibitás
  + Analízis elkerülése/megnehezítése
  + Licenszelési resztikciók

+ Hogyan?
  + API-kkal
    + Hypervizor megmondja az api-ján keresztül hogy tes virtualizálva vagy
    + Néhány OS api másképp viselkedik ha az OS VM-en fut
  + Environment based detection
    + a környezetben futó alkalmazások / telepített alkalmazásokból kiderülhet:
      + pl linuxon open-vm-tools
      + Fut a Hyper-V time Sync Service
  + Hardware based detection
    + hardverből könnyen kiderülhet
    + virtális eszközök jelenléte pl virtual GPU
    + BIOS verzió
    + különleges interfészek
  + Side channel attack
    + idő alapú "támadások"     
      + bizonyos CPU feladatok sokkal lassabbak pl CPU info
    + Viselkedés
      + bizonyos dolgok másképp működnek mint rendesen
      + Caching, CPU hibák etc

### DOS támadás
+ támadó túlterheli a hostot hogy service outage legyen
+ CPU starvation:
  + lehasználja a CPU-t a hoszton sok kontextus váltással
+ Memory starvation
  + a támadó nagyon sok memóriát probál lehasználni hogy a VM-et és a hosztot is crashelje
+ Disk performance degradation
  + sok random írás HDD-t belasítja SSD-t pedig károsítja
+ Network spoofing:
  + ARP és más kontroll csomagok spammelése
+ Countermeasures
  + Limitek felállítása
  + vigyázni a túlfoglalással
  + audit and alert

### Unauthorized access
+ Olyanok is megprobálhatnak hozzáférni akiknek semmi dolga vele
  + morcos munkatárs
  + Hackerman lopott admin jelszóval
  + Vulnerabilities-en keresztül
+ Következménye:
  + DoS: VM-eket tőrli/kriptálja
  + Adatlopás
  + Adatok manipulálása
  + Cloudban még nagyobb a veszély
+ Countermeasures
  + fizikai és virtuális access control
  + auditing
  + backups
  + shielded VMs, Encrypted VMs

### VM escape
+ kilépni a virtualizált környezetből
+ hogy?
  + bugok kihasználásával a VMM moduljaiban vagy a hardverben
+ Spectre és Meltdown

### Hyperjacking
+ a hypervizor fölött átvenni a hatalmat
+ feltelepíteni egy másik hypervizor-t az igazi alá/főlé
 






















.
