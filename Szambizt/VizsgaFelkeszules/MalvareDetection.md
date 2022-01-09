## Malware Detection



### Signatures based approach
+ Signature: rövid byte sorozat ami minden malware-re egyedi
+ Traditional Antivirus
  + megnézi a hogy a Signature része egy adatbázisnak ha igen quarantine
+ AV vendornak meg kell szerezni az új vírust
+ manuális analízis nehézkes
+ a malware generálás autmatizálható kit-ekkel
+ kis változásokal kivédhető


### Large-scale malware analysis
+ túl sok új Signature
  + VirusTotal-on
  + Amit találnak
+ Nincs elég emberi erőforrás
+ Autmatikus analízis

### Cloud based AV
+ signature database + blacklist  + whitelist lokálisan
  + ha ezek valamelyike jelez akkor kész
+ Ha ismeretlen akkor egy online inteligens malware detektort használunk
  + data mining és machine learning



### INTELLIGENT MALWARE DETECTORS



#### Sample database
+ userek álltal beküldve
+ automatikusan checkelve
  + Feature extraction
  + Feature Selection
  + Classification
  + Clustering



#### Feature extraction
+ gyors
+ alapvető karakteriszikák megtalálása
+ **Technical security skills**
+ n-gram
  + probál matching ismétlődő karakter láncokat találni
  + n-től függ hogy milyen hosszan
  + pl:![pl](https://upload.wikimedia.org/wikipedia/commons/thumb/6/68/Six_n-grams_frequently_found_in_titles_of_publications_about_Coronavirus_disease_2019%2C_as_of_7_May_2020.svg/1024px-Six_n-grams_frequently_found_in_titles_of_publications_about_Coronavirus_disease_2019%2C_as_of_7_May_2020.svg.png)
+ strings
  + kiadja hogy milyen stringek vannak benne

#### Feature selection
+ **Data mining and statistics**
+ megfelelő tulajdonságok megtalálása melyek alapján jól meghatározhatóak a malware-k

#### Classification
+ label alapján
+ labelt adni a nem ismert mintáknak
+ Modellek
  + Deicision tree
  + Neural network
  + Support vector machine
  + k-nearest neighbour

#### Clustering
+ hasonló minták találása label nélkül
+ Megoldások
  + particioning
  + spectral
  + Density based
  + Hierarhikus

















.
