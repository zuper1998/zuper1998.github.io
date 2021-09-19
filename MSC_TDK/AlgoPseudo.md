Optic Algo:

```
TimelineEdge:
Node: NStart
Node: NEnd
Date: Start
Date: End
num: Duration 
num[Duration]: Distance between nodes
num[Duration]: Angle -- in case of one node being a city node 
```


In: N TimelineEdge's, K Nodes, StartTimelineEdge, Node: Target

Out: Best Path

Algo:
```
Num: max = 0
Array: nextRoundPaths
Path: Best
nextRoundPaths.addPath(StartTimelineEdge)
for K.size(): 
	for path in nextRoundPaths:
		for OuterEdge in path.last.Edges():
		if(OuterEdge.End is after path.last.start AND path does not contain OuterEdge.NEnd)
			Path: p = path.generateNewWith(OuterEdge)
			if(curP.getDuration()>MAX_TIME):
				try: curp.TrimToWindowSize()
				if fail: skip iteration
			if(p.NEnd == Target):
				num: curBest = curP.computeOverallTransmittance()
				if(max < curBest){
					Max = curBest
					Best = curP
			else:
				nextRound.addCurP

return Best
```


Algo: generateNewWith

In: Edge v2
Edge: v1, v2 -- where v1 is the last edge of the current path
```
num: Delta = duration from v1.End to v2.Start // The overlap
Trim(Delta,v1,v2)
return v1,v2
```

Algo: Trim

In: Edge: v1, v2, num: Delta
```
if(Delta>0):
	while(Delta>0)
		num: sv1 = v1.getDurationScaledWIthTransmittance()
		num: sv2 = v2.getDurationScaledWIthTransmittance()
		if(sv1>sv2):
			v2.popFirst()
		else if(sv2>sv1):
			v1.popLast()
		else{
			if(v1.getLastTransmittance() < v2.getFirstTransmittance()):
				v1.popLast()
			else:
				v2.popFirst()
		
		if( sizeof(v1) < MIN_WINDOW OR sizeof(v2) < MIN_WINDOW)
			return empty
		delta-=1 	
```

Algo: TrimToWindowSize 

In: Path that it is used on 
```
delta = Path duration - MAX_TIME
v1 = path.firstEdge
v2 = path.lastEdge
return Trim(delta,v1,v2)
```




