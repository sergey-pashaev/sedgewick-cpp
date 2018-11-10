# ex.3.2

## task

en: Test the random-number generator on your system by generating N
random integers between 0 and r-1 with rand() % r and computing the
average and standard deviation for r = 10, 100, and 1000 and N =
10^3, 10^4, 10^5, and 10^6.

ru: Протестируйте генератор случайный чисел в своей системе. Для этого
сгенерируйте N случайный целых чисел в диапазоне от 0 до r-1 с
помощью выражения rand() % r и вычислите среднее значение и
сренднеквадратическое отклонение для r = 10, 100 и 1000 и N = 10^3,
10^4, 10^5 и 10^6.

## solution

[ex.3.2.cpp](./ex.3.2.cpp)

```
$ ./ex.3.2
old: N=1000	R=10	avg=4.476	stddev=2.868
new: N=1000	R=10	avg=4.422	stddev=2.92539
old: N=10000	R=10	avg=4.505	stddev=2.86167
new: N=10000	R=10	avg=4.505	stddev=2.87583
old: N=100000	R=10	avg=4.50162	stddev=2.8733
new: N=100000	R=10	avg=4.49035	stddev=2.86766
old: N=1000000	R=10	avg=4.49748	stddev=2.871
new: N=1000000	R=10	avg=4.49759	stddev=2.87244
old: N=1000	R=100	avg=49.466	stddev=28.7373
new: N=1000	R=100	avg=50.841	stddev=28.7696
old: N=10000	R=100	avg=49.458	stddev=28.8734
new: N=10000	R=100	avg=49.8696	stddev=28.7728
old: N=100000	R=100	avg=49.4115	stddev=28.9027
new: N=100000	R=100	avg=49.4323	stddev=28.8505
old: N=1000000	R=100	avg=49.4834	stddev=28.8814
new: N=1000000	R=100	avg=49.498	stddev=28.9029
old: N=1000	R=1000	avg=509.366	stddev=288.749
new: N=1000	R=1000	avg=512.047	stddev=278.882
old: N=10000	R=1000	avg=502.288	stddev=288.401
new: N=10000	R=1000	avg=500.464	stddev=289.667
old: N=100000	R=1000	avg=500.849	stddev=288.696
new: N=100000	R=1000	avg=499.752	stddev=288.499
old: N=1000000	R=1000	avg=499.836	stddev=288.58
new: N=1000000	R=1000	avg=499.475	stddev=288.334
```
