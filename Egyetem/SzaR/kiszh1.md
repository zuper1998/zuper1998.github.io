
## Pipes and filters

Egyszerűsített pipeline

Definiált ki és bemenet

## Adatabsztrakció és objektumorientáció

Ojektumok invokációkkal kommunikálnak

## Esemény vezéreltség

Implicit hívás 

Reaktív 

Szelektív broadcast

Eseményt létrehozó komponens nem tudja befolyásolni annak felhasználásást

## Rétegzett rendszerek

Magas absztrakció

Újrafelhasználhatóság

Rugalmas skálázhatóság

## Repositories 

közös memória (blackboard) 

direkt hozzáférése van a komputációs egységeknek hozzá

## Táblavezérelt interpreterek

Virtálisan gépek, híd HW és program között 




## Tipikus architektúrális hibák:

Scoping woes

Not Casting Your Net Widely.

Just Focusing on Functions.

Box and Line Descriptions. 

Forgetting That It Needs to be Built. 

Lack of Platform Precision

Making Performance and Scalability Assumptions.

DIY Security.

No Disaster Recovery. 

No Backout Plan.


## Component configurator

Coach

Futási időben le és felcsatlakoztat komponenseket 

M: interfész implementáció szétválasztása, külön interfész minden komponensben a konfigurációhoz

e: Komponens, Konkrét komponens, Komponenstár, Komponensbeállító 

f: 

indítás: dinamiklus csatolás és inicializálás majd komponenshez adás 

használat:csatlakozás után végzi a feladaott, eközben úrja lehet indítani is akár 

leállítás: azokat a komponenseket leállítják melyekre nincs továbbá szükség 

h: java applet

i: Mérleg

Pro: 

Egységes komponens hozzáférés 

Központi admin 

Dinamikus komp vezérlés csatlakozás

Modularitás, optimalizálás

Con:

Biztonság

Teljesítmény overhead 

Bonyolult

## Interceptor

Címváltozás, levéltovábbítás

Elkap útközben hívásokat a kernel felé és megváltoztatja

Új szolgáltatás létrhozása keretrendszermodosítás nélkül

## Extension interface








