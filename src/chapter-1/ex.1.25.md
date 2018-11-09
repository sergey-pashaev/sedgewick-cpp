# ex.1.25

## task

en: Suppose that we use weighted quick union to process 10 times as
many connections on a new computer that is 10 times as fast as an
old one. How much longer would it take the new computer to finish
the new job than it took the old one to finish the old job?

ru: Допустим, что взвешенное быстрое объединение используется для
обработки в 10 раз большего количества соединений на новом
компьютере, который работает в 10 раз быстрее старого. На сколько
больше времени потребуется для выполнения новой задачи на новом
компьютере по сравнению с выполнением старой задачи на старом
компьютере?

## solution

```
N - size
S - operations per second

0: task(N, S) = N lg(N) / S

                      2N lg(N)
1: old = task(N, S) = -------
                         S

		                  20N lg(10N)
2: new = task(10N, 10S) = ----------
                             10 S


               20N lg(10N) S   lg(10N)         1
3: new / old = ------------- = ------- = 1 + -----
               20N lg(N) S      lg(N)        lg(N)
```

 The new task will be performed `1 + 1/lg(N)` times longer than the old one.
