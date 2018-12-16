# ex.5.2

## task

en: Modify Program 5.1 to compute N! mod M, such that overflow is no
longer an issue. Try running your program for M = 997 and N = 10^3,
10^4, 10^5, and 10^6, to get an indication of how your programming
system handles deeply nested recursive calls.

ru: Измените программу 5.1 для вычисления N! mod M без риска вызвать
переполнение. Попробуйте выполнить программу для М = 997 и N = 10^3,
10^4, 10^5 и 10^6, чтобы увидеть, как используемая система
программирования обрабатывает рекурсивные вызовы с большой глубиной
вложенности.

## solution

[ex.5.2.cpp](./ex.5.2.cpp)

```
$ ./ex.5.2 1000 997
0
$ ./ex.5.2 10000 997
0
$ ./ex.5.2 100000 997
0
$ ./ex.5.2 1000000 997
Segmentation fault (core dumped)
$ gdb --args ./ex.5.2 1000000 997
>>> r
...
>>> bt 5
#0  0x0000000000400938 in mod_factorial (n=<error reading variable: Cannot access memory at address 0x7fffff7feff0>, m=<error reading variable: Cannot access memory at address 0x7fffff7fefe8>) at /sedgewick-cpp/src/chapter-5/ex.5.2.cpp:21
#1  0x000000000040096c in mod_factorial (n=825359, m=997) at /sedgewick-cpp/src/chapter-5/ex.5.2.cpp:23
#2  0x000000000040096c in mod_factorial (n=825360, m=997) at /sedgewick-cpp/src/chapter-5/ex.5.2.cpp:23
#3  0x000000000040096c in mod_factorial (n=825361, m=997) at /sedgewick-cpp/src/chapter-5/ex.5.2.cpp:23
#4  0x000000000040096c in mod_factorial (n=825362, m=997) at /sedgewick-cpp/src/chapter-5/ex.5.2.cpp:23
(More stack frames follow...)
```
