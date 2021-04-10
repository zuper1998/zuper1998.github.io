# Notes for orbital simulations 
## K:
+ The sweet spot looks like its around the inclination of 55
+ Only Changing inclination doesnt really give a good answer 
+ long asc node seems good place to start 
+ SaVi sattelite architecture follow:
	+ `semi-major axis| eccentricity | inclination | longitude asc. node | argument of periapsis | time of periapsis | sat name `
+ rosette constellation: if i get this right it gives you a constellation that gives a good amount of visibility 
	+ SaVi's tool is great for generating satellites like this 
	+ [Relevant IEEE article](https://ieeexplore.ieee.org/document/4102386)

+ to convert lat lon alt to earth centered coordinate system use [this](https://github.com/geospace-code/pymap3d)
+ Quantum rosette 8,1 is a problem child idk why 
+ PVcoordinates can be used for reeaaaaly good position data [PVcoordinates documentation](https://www.orekit.org/site-orekit-development/apidocs/org/orekit/utils/PVCoordinates.html)

## Q:
+ what diff should i use for multiple satiletes?
	+ Maybe just different launch time? 
	+ Then what is the "GOOD" time, when will the sat arrive back to the same point over the earth?
	+ K: http://castor2.ca/08_Papers/Zenith_Ranging.pdf
+ Is True anomaly = `360*time of periapsis/orbitalperiod` ? 
