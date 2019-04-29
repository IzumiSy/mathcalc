# mathcalc
> Simple arithmetic calculater for command-line.
[![CircleCI](https://circleci.com/gh/IzumiSy/mathcalc.svg?style=svg)](https://circleci.com/gh/IzumiSy/mathcalc)

```bash
$ ./mathcalc "1+2+(10*2+(5*2))+10"
> 1+2+(10*2+(5*2))+10
------
(5*2)
= (10)
1+2+(10*2+10)+10
------
(10*2+10)
= (20+10)
= (30)
1+2+30+10
------
(1+2+30+10)
= (3+30+10)
= (3+40)
= (43)
43
```

## Build
```bash
$ make
```
## Run
```bash
$ ./mathcalc
usage: mathcalc [expression]
```

## Clean-up
```bash
$ make clean
```
