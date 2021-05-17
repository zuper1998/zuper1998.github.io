#### OGSTUN-ok létrehozása
```
ip tuntap add name ogstun mode tun
ip addr add 10.45.0.1/16 dev ogstun
ip link set ogstun up

iptables -t nat -A POSTROUTING -s 10.45.0.0/16 ! -o ogstun -j MASQUERADE

ip tuntap add name ogstun2 mode tun
ip addr add 10.46.0.1/16 dev ogstun2
ip link set ogstun2 up

iptables -t nat -A POSTROUTING -s 10.46.0.0/16 ! -o ogstun2 -j MASQUERADE
```
## Inditas
WIRESHARK!!! -- komponenses gepen 

### GNB es UE
```
./nr-gnb -c ../config/open5gs-gnb.yaml
```
```
./nr-ue -c ../config/open5gs-ue0.yaml 
./nr-ue -c ../config/open5gs-ue1.yaml 

```
## UE beregisztralasa -- Komponensen
```
sudo apt update
sudo apt install curl
curl -fsSL https://deb.nodesource.com/setup_14.x | sudo -E bash -
sudo apt install nodejs
```
localhost:3000 
admin@1423

### BEALITASOK
UE0
![](https://gyazo.com/8fc312ceb03f60928402680538bd2f8a.png =650x)
UE1
![](https://gyazo.com/5c871b65ca2b888aad0062913690df91.png =650x)
Restart gNB 

## Teszteles: 
```
ping google.com -I uesimtun0 -n
