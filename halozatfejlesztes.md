# Tutorial 

### Kiosztás
10.1.2.101: Komponensek -- AMF SMF
10.1.2.102: UE és gNB
10.1.2.103: UPF -- 2 DB

### Komponensek: 
`sudo apt update`
`sudo apt install software-properties-common`
`sudo add-apt-repository ppa:open5gs/latest`
`sudo apt update`
`sudo apt install open5gs`

AMF.yaml modositasa:
178 sor
````
amf:
    sbi:
      - addr: 127.0.0.5
        port: 7777
    ngap:
      - addr: 10.1.2.101
    guami:
      - plmn_id:
          mcc: 001
          mnc: 01
        amf_id:
          region: 2
          set: 1
    tai:
      - plmn_id:
          mcc: 001
          mnc: 01
        tac: 1
    plmn_support:
      - plmn_id:
          mcc: 001
          mnc: 01
        s_nssai:
          - sst: 1
            sd: 1

````

### smf.yaml
319. sor
```
smf:
    sbi:
      - addr: 127.0.0.4
        port: 7777
    pfcp:
      - addr: 10.1.2.101
      - addr: ::1
    gtpc:
      - addr: 127.0.0.4
      - addr: ::1
    gtpu:
      - addr: 127.0.0.4
      - addr: ::1
    subnet:
      - addr: 10.45.0.1/16
        dnn: internet
      - addr: 10.46.0.1/16
        dnn: internet2
```
427  sor: 
```
upf:
    pfcp:
      - addr: 10.1.2.103
        dnn: [internet, internet2]
```

### UE gNB
URANSIM: 
```
cd ~
git clone https://github.com/aligungr/UERANSIM
```
### UPF
#### upf.yaml
```
upf:
    pfcp:
      - addr: 10.1.2.103
    gtpu:
      - addr: 10.1.2.103
    subnet:
      - addr: 10.45.0.1/16
        dnn: internet
        dev: ogstun
      - addr: 10.46.0.1/16
        dnn: internet2
        dev: ogstun2
```
### gnb.yaml

```
mcc: '001'          # Mobile Country Code value
mnc: '01'           # Mobile Network Code value (2 or 3 digits)

nci: '0x000000010'  # NR Cell Identity (36-bit)
idLength: 32        # NR gNB ID length in bits [22...32]
tac: 1              # Tracking Area Code

linkIp: 10.1.2.102   # gNB's local IP address for Radio Link Simulation (Usually same with local IP)
ngapIp: 10.1.2.102   # gNB's local IP address for N2 Interface (Usually same with local IP)
gtpIp: 10.1.2.102    # gNB's local IP address for N3 Interface (Usually same with local IP)

# List of AMF address information
amfConfigs:
  - address: 10.1.2.101
    port: 38412

# List of supported S-NSSAIs by this gNB
slices:
  - sst: 1
    sd: 1

# Indicates whether or not SCTP stream number errors should be ignored.
ignoreStreamIds: true
```

#### UE config 0

```
# IMSI number of the UE. IMSI = [MCC|MNC|MSISDN] (In total 15 or 16 digits)
supi: 'imsi-001010000000000'
# Mobile Country Code value of HPLMN
mcc: '001'
# Mobile Network Code value of HPLMN (2 or 3 digits)
mnc: '01'

# List of gNB IP addresses for Radio Link Simulation
gnbSearchList:
  - 10.1.2.102

# Initial PDU sessions to be established
sessions:
  - type: 'IPv4'
    apn: 'internet'
    slice:
      sst: 1
      sd: 1
    emergency: false

# Configured NSSAI for this UE by HPLMN
configured-nssai:
  - sst: 1
    sd: 1

# Default Configured NSSAI for this UE
default-nssai:
  - sst: 1
    sd: 1

# Supported encryption algorithms by this UE
integrity:
  IA1: true
  IA2: true
  IA3: true

# Supported integrity algorithms by this UE
ciphering:
  EA1: true
  EA2: true
  EA3: true

# Integrity protection maximum data rate for user plane
integrityMaxRate:
  uplink: 'full'
  downlink: 'full'
```

#### UE 1
```
# IMSI number of the UE. IMSI = [MCC|MNC|MSISDN] (In total 15 or 16 digits)
supi: 'imsi-001010000000001'
# Initial PDU sessions to be established
sessions:
  - type: 'IPv4'
    apn: 'internet2'
    slice:
      sst: 1
      sd: 1
    emergency: false
```
