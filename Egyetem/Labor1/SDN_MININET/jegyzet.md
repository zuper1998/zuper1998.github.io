Openflow 1.0 vs 1.1 -- több táblával dolgozik az 1.1

# Ismertesd az OpenFlow ajánlás lényegét! 

Virtuaizált hálozati kontroll

# Milyen elemei vannak egy OpenFlow hálózatnak? 
switch kontroller, switchen belül csatorna és folyamtábla 

# Milyen OpenFlow switch-eket ismersz? (Természetesen nem a konkrét típusok kellenek...) 


Virtuális
Open vSwitch 
Rendes

#  Mit tudsz az Open vSwitch-ről? 
kernel space-ben müködik 

nem csak openflow 

OS Virtualizációs programokban is használják 

# Hogyan épül fel egy OpenFlow flow bejegyzés? 

mi esetén mit kell csinálni mennyi ideig 

# Milyen fejrész mezők illeszkedése vizsgálható egy 1.0-ás OpenFlow switch-ben? Sorolj fel legalább hatot! 

MAC IPV4 TCP/UDP port forrás és cél 

#  Ismertesd, hogyan történik egy csomag továbbítása a hálózatban abban az esetben, ha az OpenFlow switch-ek flow táblája üres és egy NOX kontroller vezérli a hálózatot! 

Noxnak elküldi és az megmondja mit kell csinálni 


# Mi a feladata a NOX-nak egy OpenFlow hálózatban? 

táblák feltöltése 


# Milyen fontosabb események használhatók egy NOX alkalmazásban? 

Megérkezik a csomag 

Eldobják a csomagot 

#  Milyen programozási interfésze van a NOX-nak? 

c++ de python is lehet (ez már POX)

#  Mire való a Mininet program? 

Hálózati topo szim 


#  Milyen hálózati komponensek használhatók a Mininet programban? 

hoszt switch link 














