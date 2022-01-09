### Támadások
+ jelszó nincs de fizikai hozzáférés van
  + Grub-ban e -- edit
  + linux sor végére init=bin/bash -- init helyet kapunk egy shellt
  + passwd root nem megy előszőr mert nincs felcsatolva a /
  + mount -o remount,rw /
  + ezután megy a passwd
  + sync
  + exit -- kernel panic mert init az nem volt jó
+ Ssh kapcsolatból priv esc
  + suid bináris keresése
    + find / -perm 4000 -user root
    + itt talált egy egyedi fájlt ami: /pub/apachemanage/apachemanage volt
  + kihasználni a hibát hogy shell-t kapjon
  + apachemanage "start && id"
    + vissza adja hogy rootként futunk
  + apachemanage "start && /usr/sbin/adduser bob sudo" -- hozzáadjuk magunkat a sudoershez
+ Rootként fut folyamat egy script pl cron
  + irni nem szabad
  + de törölni igen :)
  + törölni a script.sh-t és csinálni sajátot
  + ott adni magunknak sudo jogosultságokat
+ SSH daemon kicserélése -- perzisztencia szerzése
  + kicserélni hogy minden jelszóval be engedjen
+ perzisztencia szerzés még:
  + authorized_keyd-be bele rakja a asját kulcsát
+ root jog még:
  + passwd-be felvenni egy új usert akinek az user id-ja 0 -- root lesz az is


### Védekezés
+ LUKS -- linux unified key setup
  + macerás csinálni ha már kész install van
  + telepítéskor ajánlott bekattintani
+ Szép megoldás az apachemanage helyet
  + vim /etc/sudoers
  + Cmnd_Alias APACHE2 = /usr/sbin/service apache2 *
+ kicserélt binárisok észrevétele
  + debsums -- átnézi a hashsumokat
+ Átnézni az etc/passwd fájl és az authorized_key-t
+ shh hardening
  + /etc/ssh/sshd_config
  + jelszó tiltása: password authentication no
  + Rebex ssh check
  + fail2ban -- ha sokszor nem jó a pwd akkor ban the ip


### Info
+ suid:
  + különleges jogosúltsági bit amitől az mindig a tulajdonos jogosúltságaival fog futni
  + pl van egy root által létrehozott bináris suid-al és azt futattja bob akkor az rootként fog futni
