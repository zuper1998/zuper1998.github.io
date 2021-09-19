## ITS protocoll stack: 

![protocol stack](https://gyazo.com/5b2464e22a6c1ea3521160298c0689db.png)


## 802.11/Wawe/DSRC:

DSRC -- dedicated shor range communications 

Támogatott modulációl: BPSK, QPSK, 16QAM, 64QAM

Kódolási arányok: 1/2,2/3,3/4

7 csatorna: **6 szolgáltatási csatorna**,**1 valós idejű a biztonságos kapcsolathoz**

EU frekvencia allokáció: **5,850 -- 5,925 GHz**

Frekvencia tartomány:

![Frekvencia tartomany](https://gyazo.com/01b400c3963da2e24e447c8189de7772.png)

## Geo networking protokoll

Hálózat rétegbeli protokoll
Két féle állomás tipus:
+ RSU -- Road Side Unit: V2I, erős rádiós képesség, magas számítási kapacitás, fix pozició
+ OBU -- On-Board Unit:  Járművekben elhelyezve, változik a poziciója emiatt 

### GeoNetworking  címek: 

Minden állomást egy egyedi GeoNetworking cím azonosít. A GeoNetowrking Cím megtalálható minden csomag fejlécében

![GeoNetworking cim felepitese](https://gyazo.com/8faffb0c8044bb823c1f36060120f404.png)

```
M: manuálisan állították e be a címet - 1 igen, 0 nem 

ST: ITS-S tipusát adja meg 

MID: hozzáférési hálózat címe, ITS-G5 alatt ez 48 bites MAC (LL_ADR - LOW LEVEL ADDRESS)
```


### GeoNetworking adatstruktúrák

Minden GeoAdhoc router egy lokációs táblát tart karban, ebben a következők vannak:

GN_ADDR - ITS-S GeoNetworking címe

LL_ADDR - ITS-S MAC címe 

TYPE_ITS_S - ITS-S tipusa

GeoNetworking_version - verzió 

PV: Position Vector 
```
Földrajzi pozició: POS(GN_ADDR)

Sebesség: S(GN_ADDR)

Haladás iránya H(GN_ADDR)

Földrajzi pozició időbélyege: TST(POS, GN_ADDR)

Pocició pontosság indikátor P AI(POS, GN_ADDR)
```

LS_PENDING(GN_ADDR): Location Service folyamatban van e 

IS_NEIGHBOUR(GN_ADDR): GeoAdhoc router szomszédos e 

SN(GN_ADDR): Szekvencia sorszám 

TST(GN_ADDR): Időbélyeg 

PDR(GN_ADR): Packed data rate 
 

### GeoNetworking csomag felépítése:


Fejléc: 

![Fejlec](https://i.gyazo.com/298a31629bbc0262854ce7f191d0189a.png)


3 részből tevődik össze: 
+ basic
+ common 
+ extended: tartalma és mérete a csomag tipusától függ

A basic header felépítése minden csomagtipus esetén azonos: 

![basic header](https://i.gyazo.com/f83903b7891ac80cb56a23cc8603fcf7.png)


A közös fejléc a csomag küldőjének földrajzi pozicióját tartalmazza. Felépítése minden csomagtipus esetén azonos.


![Common header](https://gyazo.com/5f7cd7a21fe22f937c9bf5f46c128815.png)


Fontosabb mezők: 
+ NH - Next Header: a csomag tipusát: BTP-A, BTP-B, IPv6
+ HT - Header type: a csomag tipusát adja meg az alábbi értékek szerint:

![csomagtipus](https://gyazo.com/e058e9ebfe4589d606eda6b8eaf1c9fa.png)

**Fontosabb üzenettipusok:**

![](https://gyazo.com/3abe62f9fc72fe8ce97dfb36e3f82078.png)



























