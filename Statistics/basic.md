# Statistics
    
- purpose (to find-out)
  - phenomenon (group characteristics)
  - reason-result (relationship of factotrs)
  - economic, social  tendencies(, rules)
    - used for predicting future, and helping decision
    
- how
  - survey
  - experiment
  - observation
    
- terms
  - unit
    - person
    - state
    - food
    - ...
  - case (record)
  - variable
    
- level of measurement (scale of measure)
  - **nominal scale** : identifying use
  - **ordinal scale** : serial ordering use
  - **interval scale** : scoring use
  - **ratio scale** : ratio use
    
- data
  - value's level
    - qualitaive value
    - quantitative value
  - value's quantity
    - single-meaning value
    - multi-meaning values
    
- data, information repository
  - korea
    - (kostat)[kostat.go.kr]
    - (kosis)[kosis.kr]
    - (korea-index)[index.go.kr]
    - (micro data service)[mdis.kostat.go.kr]
    - (statstic-geographic information)[sgis.kostat.go.kr]
    - (economic information)[ecos.bok.or.kr]
  - global
    - (StRD)[itl.nist.gov/div898/strd]
    - (DASL)[dasl.datadescription.com]
    - (UCI data)[archive.ics.uci.edu]
    - (ksdc)[ksdc.re.kr]
    - (usa statistics)[usa.gov/statistics]
    
- center tendency
  - mean
    ```R
    mean(data)
    ```
  - trimmed mean
    ```R
    mean(data, trim=0.10)
    ```
  - median
    ```R
    median(data)
    ```
  - mode
    ```R
    mode(data)
    ```

- dispersion
  ```R
  summary(data)
  ```
  - variance
    ```R
    ```
  - standard deviation
    ```R
    sd(data)
    ```
  - range
    ```R
    ```
  - coefficient of variation
    ```R
    ```
  -quartile deviation
    - interquartile range : Q3 - Q1
    ```R
    IQR(data)
    quantile(data, probs=c(0.25, 0.5, 0.75))  //it's quaNtile, not quaRtile
    ```
   
- continuous data graph 
  - histogram
    ```R
    a = rnorm(200)
    hist(a, col="RED")
    ```
  - stem leaf
