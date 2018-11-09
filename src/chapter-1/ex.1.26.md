# ex.1.26

## task

en: Answer Exercise 1.25 for the case where we use an algorithm that
requires N^3 instructions.

ru: Выполните упражнение 1.25 для случая использования алгоритма,
который требует выполнения N^3 инструкций.

## solution

```
N - size
S - operations per second

0: task(N, S) = N^3 / S

1: old = task(N, S) = N^3 / S

2: new = task(10N, 10S) = (10N)^3 / 10S

               (10N)^3 S   10^3 N^3 S
3: new / old = --------- = ---------- = 10^2 = 100
                N^3 10S    10   N^3 S
```

 The new task will be performed `100` times longer than the old one.
