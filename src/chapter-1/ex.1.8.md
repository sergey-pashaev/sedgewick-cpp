# ex.1.8

## task

en: Do Exercise 1.4, but use the weighted quick-union algorithm with
path compression by halving (Program 1.4).

ru: Выполните упражнение 1.4, но для алгоритма взвешенного быстрого
объединения со сжатием пути делением пополам (программа 1.4).

## solution
```
* weight indicated in brackets

input 0,2  id: 0(2) 1(1) 0(1) 3(1) 4(1) 5(1) 6(1) 7(1) 8(1) 9(1)  accesses: 3
input 1,4  id: 0(2) 1(2) 0(1) 3(1) 1(1) 5(1) 6(1) 7(1) 8(1) 9(1)  accesses: 3
input 2,5  id: 0(3) 1(2) 0(1) 3(1) 1(1) 0(1) 6(1) 7(1) 8(1) 9(1)  accesses: 8
input 3,6  id: 0(3) 1(2) 0(1) 3(2) 1(1) 0(1) 3(1) 7(1) 8(1) 9(1)  accesses: 3
input 0,4  id: 0(5) 0(2) 0(1) 3(2) 1(1) 0(1) 3(1) 7(1) 8(1) 9(1)  accesses: 8
input 6,0  id: 0(7) 0(2) 0(1) 0(2) 1(1) 0(1) 3(1) 7(1) 8(1) 9(1)  accesses: 8
input 1,3  id: 0(7) 0(2) 0(1) 0(2) 1(1) 0(1) 3(1) 7(1) 8(1) 9(1)  accesses: 12
total accesses: 45

```
