### Kiosztás
```
10.1.2.101: Komponensek -- AMF SMF
10.1.2.102: UE és gNB
10.1.2.103: UPF -- 2 DB
```
### Komponensek: 
```
sudo apt update
sudo apt install software-properties-common
sudo add-apt-repository ppa:open5gs/latest
sudo apt update
sudo apt install open5gs
sudo apt update
sudo apt install mongodb
systemctl start mongodb
systemctl enable mongodb
```

### UE gNB
URANSIM: 
```
cd ~
sudo apt install git
sudo snap install cmake --classic
sudo apt install g++
sudo apt install libsctp-dev lksctp-tools
sudo apt install iproute2
git clone https://github.com/aligungr/UERANSIM
cd UERANSIM
make
```
### UPF
```
sudo apt update
sudo apt install software-properties-common
sudo add-apt-repository ppa:open5gs/latest
sudo apt update
sudo apt install open5gs
sysctl -w net.ipv4.ip_forward=1
```
