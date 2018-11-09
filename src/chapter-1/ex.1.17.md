# ex.1.17

## task

en: Answer Exercise 1.4, but using the weighted quick-union algorithm
with full path compression (Exercise 1.16).

ru: Выполните упражнение 1.4, но используйте алгоритм взвешенного
быстрого объединения с полным сжатием пути (упражнение 1.16).

## solution
```
* weight indicated in brackets

input 3,4  id: 0(1) 1(1) 2(1) 3(2) 3(1) 5(1) 6(1) 7(1) 8(1) 9(1)  accesses: 8
input 4,9  id: 0(1) 1(1) 2(1) 3(3) 3(1) 5(1) 6(1) 7(1) 8(1) 3(1)  accesses: 13
input 8,0  id: 8(1) 1(1) 2(1) 3(3) 3(1) 5(1) 6(1) 7(1) 8(2) 3(1)  accesses: 8
input 2,3  id: 8(1) 1(1) 3(1) 3(4) 3(1) 5(1) 6(1) 7(1) 8(2) 3(1)  accesses: 8
input 5,6  id: 8(1) 1(1) 3(1) 3(4) 3(1) 5(2) 5(1) 7(1) 8(2) 3(1)  accesses: 8
input 5,9  id: 8(1) 1(1) 3(1) 3(6) 3(1) 3(2) 5(1) 7(1) 8(2) 3(1)  accesses: 13
input 7,3  id: 8(1) 1(1) 3(1) 3(7) 3(1) 3(2) 5(1) 3(1) 8(2) 3(1)  accesses: 8
input 8,4  id: 8(1) 1(1) 3(1) 3(9) 3(1) 3(2) 5(1) 3(1) 3(2) 3(1)  accesses: 13
input 6,1  id: 8(1) 3(1) 3(1) 3(10) 3(1) 3(2) 3(1) 3(1) 3(2) 3(1)  accesses: 18
total accesses: 97

```
