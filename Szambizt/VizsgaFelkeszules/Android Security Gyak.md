### Támadás
+ apk lehúzása telefonból
  + adb-vel listázni a 3rd party apk-kat majd lekérni hozzá a path-et
  + zipként kitömöríthető
+ classes.dex kicsomagolása
  + strings-el
  + dex2jar
    + a jar-t a jadx-gui-val lehet visszafejteni
  + egyből jadxgui-val az apk-t
+ Kód manipuláció
  + smaliba kell visszafejteni
    + így egyszerűen lehet oda vissza fordítani
    + apktool-al lehet
    + cursed nyelv
    + java primitívek vannak benne, pl Z = boolean :D
+ Debug userek bent maradtak
  + megoldás, check for build type
### Védekezés
+ proguard
  + gradle-ben lehet aktiválni


### Info
 + classes.dex
