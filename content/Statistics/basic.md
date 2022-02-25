---
title: "Statistics basic"
author: "Niiok"
categories: ["Statistic"]
date: 1970-01-01T00:00:00+00:00
weight: 1


# searchHidden: true

#cover:
#    image: "<image path/url>"    # can also paste direct link from external site
#    alt: "<alt text>"
#    caption: "<text>"
#    relative: false 	# To use relative path for cover image, used in hugo Page-bundles

#ShowBreadCrumbs: false
---

    
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
    - [kostat](http://kostat.go.kr)
    - [kosis](http://kosis.kr)
    - [korea-index](http://index.go.kr)
    - [micro data service](http://mdis.kostat.go.kr)
    - [statstic-geographic information](http://sgis.kostat.go.kr)
    - [economic information](http://ecos.bok.or.kr)
  - global
    - [StRD](http://itl.nist.gov/div898/strd)
    - [DASL](http://dasl.datadescription.com)
    - [UCI data](http://archive.ics.uci.edu)
    - [ksdc](http://ksdc.re.kr)
    - [usa statistics](http://usa.gov/statistics)
    
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
  - quartile deviation
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
  - stem-and-leaf
    ```R
    stem(data)
    stem(data, scale=2)
    ```
  - box plot
    ```R
    boxplot(data)
    ```
    - five-number-summary
    -adjacent value
    
- web tool
  - [statpages](http://statpages.org)
  - [inteructivate](http://shodor.org/intructivate/activities)