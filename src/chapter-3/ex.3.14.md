# ex.3.14

## task

en: The C++ standard library includes the Vector data type as an
alternative to arrays. Find out how to use this data type on your
system, and determine the effect on the runtime when you replace
the array in Program 3.5 by a Vector.

ru: Стандартная библиотека С++ в качестве альтернативы массивам
содержит тип данных vector. Узнайте, как использовать этот тип
данных в своей системе, и определите его влияние на время
выполнения, если заменить в программе 3.5 массив типом vector.

## solution

```
$ ./ex.3.14.sh
memory usage of ./program.3.5 (massif.out.21463):
...
Number of snapshots: 52
 Detailed snapshots: [11, 47 (peak)]
...
--------------------------------------------------------------------------------
  n        time(B)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 47      4,197,552           82,560           76,800            16        5,744


memory usage of ./ex.3.14 (massif.out.21467):
...
Number of snapshots: 61
 Detailed snapshots: [15, 48, 50, 51, 52 (peak)]
...
--------------------------------------------------------------------------------
  n        time(B)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 52      4,280,824           82,600           80,800            24        1,776

cpu usage of ./program.3.5:
==21470== Events    : Ir
==21470== Collected : 2333599
==21470==
==21470== I   refs:      2,333,599

cpu usage of ./ex.3.14:
==21471== Events    : Ir
==21471== Collected : 2392243
==21471==
==21471== I   refs:      2,392,243
```
