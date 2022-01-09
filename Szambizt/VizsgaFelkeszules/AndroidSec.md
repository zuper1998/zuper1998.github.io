### Android


### App signing
+ Kell de nem nincs trusted CA aki adja a signing jogosultságod
+ self signed is okay
+ De attól még jó:
  + update is ezzel kell legyen aláírva
+ többet is tartalmazhat pl v1 és v2 is lehet
+ A legmagasabb számukra érthető signing típust használja majd az eszköz


### App signing fajtái
+ v1
  + hash minden fájlra, a has lista van aláírva
  + lassú
+ v2
  + egy blob az egész apk
  + gyorsabb
+ v3
  + lehet rotálni az aláíró kulcsokat
+ v4
  + aláírás nem az apk-ban hanem egy .idsig fájlban
  + v2 vagy v3 kell
  + streaming támogatás

### Rooting
+ bármit megtehetsz amit linuxon
  + sajnos ebbe beletartozik az is hogy masszívan elrontasz valamit
+ PRO:
  + modding
  + bloatware leszedése
  + cpu over underclocking
  + Előre telepített vírusok leszedése -- 中華民國光榮
+ CON:
  + lehet a garanciát érvényteleníti -- EU-ban nem European Directive 1999/44/EC LFG
  + könnyű a telefon -> tégla transzformációt végrehajtani
  + pár helyen illegális

  
### Rooting methods
+ Soft root
  + kernel exploital
  + veszélyes mert vírusok is felhasználhatják
+ Hard root
  + boot loader-el costum ROM-ot rakunk rá root támogatással
  + biztonságosabb



### Google SafetyNet
+ 4 Google serviceből áll
  + Safe Browsing API -- a kind of a URL blacklist
  + reCAPTCHA API -- provides CAPTCHA support for apps
  + Verify Apps API -- checks for installed known bad apps
  + Attestation API -- makes it possible for apps to check how 'safe' a device is

### Safe Mode
+ gomb kombó által lehet bele bootolni
+ csak core appok működnek

### Screen overlay
+ draw over other apps
+ külön engedélyezni kell mert könnyen abuse-álható

### Device administrator
+ lock screen működésének megváltoztatása
+ elvárhatja
  + erős jelszavakat
  + enkriptált tárhelyet
+ disable camera
+ remote wipe


### Andoid AV
+ nem tudd nagyon semmit csinálni
+ call blocking
+ "secure" vpn
+ phishing protection
+ remote wipe


### Find my device
+ Lehet:
  + lock phone
  + hol volt phone
  + remote wipe phone

### ADB -- Android debug bridge
+ developer optionsben enable
+ install run debug apps usb-n keresztül

### Verified boot
+ root of trust a vbmeta, ellenőrzi a boot system és vendor részeket
+ rollback protection

### Új security feature-ek  android 10ben
+ location access restricted
  + csak mikor nyitva van az app
+ Adiantum
  + lighweight crypto module ahol nincs hardveres
+ TLS 1.3
+ One time permission
+ Privacy dashboard
  + app privilige usage

### Protecting your apps
+ kell mert:
  + ne kalózkodják
  + ne csaljanak benne
  + ne lopjanak adatot
+ Hostile enviroment detection
  + are we in a simulation
    + mobile carrier check
  + installer detection
  + Root bootloader detecton
    + Google safety net api
    + létezik e su vagy busybox
  + Tamper detection
    + jó key-el van aláírva?

### Obfuscation
+ nehéz legyen visszafejteni
+ kód újra írása és újra strukturálása anélkül hogy megváltozna mit csinál s
+ Technikák
  + name
  + string
  + value
  + control flow
  + code encryption
  + code virtualization









.
