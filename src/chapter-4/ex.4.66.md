# ex.4.66

## task

en: Write a program to determine empirically the probability that
various poker hands are dealt, using your ADT from Exercise 4.65.

ru: Используя АТД из упражнения 4.65, напишите программу, которая
опытным путем определяет вероятность раздачи различных наборов карт
при игре в покер.

## solution

[ex.4.66.cpp](./ex.4.66.cpp)

```
$ ./ex.4.66 1000000
422090:1000000 pair (0.42209)
47512:1000000 two pair (0.047512)
21197:1000000 trips (0.021197)
3148:1000000 straight (0.003148)
1906:1000000 flush (0.001906)
1438:1000000 full house (0.001438)
223:1000000 quad (0.000223)
12:1000000 straight flush (1.2e-05)
```
