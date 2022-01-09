## Container Security
+ alap konténeres cuccokat nem írom le ide
+ basically nagyobb izoláció

### Chroot jail
+ izolálod a szoftvert és gyermekeit a többitől
+ könnyen kilépsz

### FreeBSD jail
+ mint chroot de itt egy mást view-t is kapnak a filesystemről az alkalmazások


### Docker architektúra
+ 4 részre osztható
  + Docker engine,
  + containerd,
  + containerd-shim
  + runC


### DOCKER ENGINE SECURITY
+ ne lehessen konténerek között átnyulni
  + namespace: magas szintű izoláció
+ Minden konténernek saját namespace és saját network stack


### Linux kernel: control groups
+ resource limiting

### Linux kernel: capabilities
+ root/ nem rootból csinált egy actually menedzselhető hozzáférési jogosultságos dolgot
+ pl: net_bind_service elég ahhoz hogy fusson egy porton
+ docker allowlist alapján tartja meg a daemonnak ami kell neki



### Docker daemon attack surface
+ rootként kell futtatni
+ docker daemont csak olyanok használhatják akiben megbízunk különben kaka

### Docker content trust
+ verify integrity of publisher and the data received
+ Docker content trust: digital signature for signing data sent and received to remote docker registries

### Vulnerability Scanning
+ security state checking
+ hiba helyét is mutatja


















.
