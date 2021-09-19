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





## BTP -- Basic Transport Protocol

Kapcsolatmentes

Point-to-Point

GeoNetworkingre épül 

BTP-A: **interaktív kétirányú**

BTP-B: **egyirányú**

### Header felépítés beli különbségek:

![](https://gyazo.com/e81e94387f10e074323f27d033aeea1c.png)



## ITRI WAVE/DSRC 

32 bites Big Edian proci -- Normális a little edian

Linux kernel fut -- 2.6.32.45



## Konfiguráció:

### Sávszélesség és vivő konfiguráció

![](https://gyazo.com/27f410f8952248eac6186cf73f8344c1.png)

`echo "wave0 XX@YYYY" > /proc/sys/wave/channel`

### Adási teljesítmény: 


` echo "wave0  X" > /proc/sys/wave/txpower` -- X in \[9 , 25]

### Adatátviteli sebesség: 

![](https://gyazo.com/f5ba812f68c490be1fbeea82a3ccc5d5.png)

`echo "wave0 X" > /proc/sys/wave/txrate`


### Statisztikák

`cat /proc/sys/wave/stats`


### Üzenetek frekvenciájának beállítása 

`echo X > /proc/sys/net/gn/bea_retrans_timer ` -- X\[ms]  

### GN csomagok élettartama

`echo X > /proc/sys/net/gn/default_pkt_lifetime ` -- X \[s]

### SAJAT GN címhez tartozó adatok megtekintése

`cat /proc/net/gn/lpv `


### Szomszédos GN címek(hez) tartozó adat(ok) megtekintése 

`cat /proc/net/gn/loc `


### GN helyinformációk beállítása

```
echo 511234567 > /proc/sys/net/gn/local_latitude 
echo 51234567 > /proc/sys/net/gn/local_longitude 
```


## C++ part

### Create, bind and use socket:

`int socket(int domain, int type, int protocol)`

In our case we will be using: 

`sd = socket(PF_BTP, SOCK_RAW,0);`

We bind it with: 

`int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) `

where: 

`err = bind(sd, (struct sockaddr*) &sbs, sizeof(sbs)); `

We use it by: 

`sendto(sd, msg, 2048, 0, (struct sockaddr *) &sbs, sizeof(sbs))); `

We receive these texts by: 

`int recvfrom(sd, msg, 2048, 0, (struct sockaddr *) &sbs, &len)`

And at last we can close it with: 

`close(sd)`



































