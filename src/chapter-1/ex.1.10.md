# ex.1.10

###### task

en: Estimate the minimum amount of time (in days) that would be
required for quick find (Program 1.1) to solve a problem with
10^9 objects and 10^6 input pairs, on a computer capable of executing
10^9 instructions per second. Assume that each iteration of the inner
for loop requires at least 10 instructions.

ru: Определите минимальное время (в днях), которое потребовалось бы
для выполнения быстрого поиска (программа 1.1) для решения задачи с
10^9 объектов и 10^6 вводимых пар на компьютере, который может
выполнять 10^9 инструкций в секунду. Считайте, что при каждой итерации
внутреннего цикла for должно выполняться не менее 10 инструкций.

###### solution
```
N = 10^9 objects
M = 10^6 edges
Speed = 10^9 op/second
For > 10 op

(N * M * For ) / Speed = 10^7 seconds ~ 115.7 days
```
