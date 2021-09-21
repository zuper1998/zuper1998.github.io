# HDSF -- Hadoop Distributed File System 

## Arhitecture

![](https://i.imgur.com/nJo56P9.png)


![](https://i.imgur.com/IZkzkIA.png)

Block structured system with predermined size 

Master/Slave architecture 

### Name Node 
+ maintains and manages the Data nodes (slaves)
+ Records Metadata of files stored 
	+ FsImage: Complet state of system since start of NameNode
	+ EditLogs: all recent modifications 
+ receives hearthbeat and block report from data nodes
+ responsible for the replication factor 
+ in case of a data node failure it chooses a new one 


### DataNode: 

Slave Node 

Nonspecialized hardware 

Funcions:
+ slave daemons on each slave machine 
+ Actual data is stored here
+ only performs low level read/write functions 
+ sends hearthbeats to NameNode


### Secondary NameNode: 

![](https://i.imgur.com/pkfXGF8.png)


NOT a backup NameNode 




