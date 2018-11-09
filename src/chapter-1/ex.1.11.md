# ex.1.11

## task

en: Estimate the maximum amount of time (in seconds) that would be
required for weighted quick union (Program 1.3) to solve a prolem with
10^9 objects and 10^6 input pairs, on a computer capable of executing
10^9 instructions per second. Assume that each iteration of the outer
while loop requires at most 100 instructions.

ru: Определите максимальное время (в секундах), которое потребовалось
бы для выполнения взвешенного быстрого объединения (программа 1.3) для
решения задачи с 10^9 объектов и 10^6 вводимых пар на компьютере,
который может выполнять 10^9 инструкций в секунду. Считайте, что при
каждой итерации внешнего цикла while должно выполняться не более 100
инструкций.

## solution
```
N = 10^9 objects
M = 10^6 edges
Speed = 10^9 op/second
While < 100 op

(M * (log N * 2 + 1) * While) / Speed ~ 3.1 seconds
```
