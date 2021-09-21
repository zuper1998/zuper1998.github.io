# HDSF -- Hadoop Distributed File System 

## Arhitecture

![](https://i.imgur.com/nJo56P9.png)


![](https://i.imgur.com/IZkzkIA.png)

Block structured system with predermined size 

Master/Slave architecture 

Hadoop cluster Architecture:

![](https://i.imgur.com/DXtlvb1.png)


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

Combines EditLogs with FsImage and copies it back to the NameNode which is used when it starts up again 

Reads Metadata from the RAM of NameNode and writes it to the hdd 

### Blocks

blocksize is 128MB -- big to avoid overhead due to many blocks 

### Replication Management 

![](https://i.imgur.com/DEsAyB8.png)

The data is stored trough block along multiple nodes, these blocks are replicated to increase robostusness 

### Rack Awareness 

![](https://i.imgur.com/mbfQ2tp.png)

Ensures that the replicas are not stored on the same rack 


### HDFS read write architecture 

Follows: Write once read many

`
