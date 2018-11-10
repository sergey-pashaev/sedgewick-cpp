# ex.3.11

## task

en: Modify our implementation of the sieve of Eratosthenes (Program
3.5) to use an array of (i) chars; and (ii) bits. Determine the
effects of these changes on the amount of space and time used by
the program.

ru: Измените реализацию решета Эратосфена (program.3.5) для
использования массива (1) символов и (2) разрядов. Определите
влияние этих изменений на расход памяти и времени, используемых
программой.

## solution

[ex.3.11.sh](./ex.3.11.sh)


```
$ ./ex.3.11.sh
memory usage of ./ex.3.11.char (massif.out.27216):
...
Number of snapshots: 80
 Detailed snapshots: [22, 36, 48, 52, 57, 67, 68, 69, 70 (peak)]
...
--------------------------------------------------------------------------------
  n        time(B)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 70      7,285,176           80,424           77,552           152        2,720


memory usage of ./ex.3.11.bit (massif.out.27297):
...
Number of snapshots: 62
 Detailed snapshots: [23, 48, 58, 59 (peak)]
...
--------------------------------------------------------------------------------
  n        time(B)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 59     10,362,424           80,584           77,552           152        2,880

cpu usage of ./ex.3.11.char:
==27300== Events    : Ir
==27300== Collected : 4494978
==27300==
==27300== I   refs:      4,494,978

cpu usage of ./ex.3.11.bit:
==27354== Events    : Ir
==27354== Collected : 5053506
==27354==
==27354== I   refs:      5,053,506
```
