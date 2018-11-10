# ex.3.3

## task

en: Test the random-number generator on your system by generating N
random numbers of type double between 0 and 1, transforming them to
integers between 0 and r-1 by multiplying by r and truncating the
result, and computing the average and standard deviation for r =
10, 100, and 1000 and N = 10^3, 10^4, 10^5, and 10^6.

ru: Протестируйте генератор случайный чисел в своей системе. Для
этого сгенерируйте N случайный чисел типа double в диапазоне от 0
до 1, преобразуя их в целые числа диапазона от 0 до r-1 путем
умножения на r и усечения результата. Затем вычислите среднее
значение и сренднеквадратическое отклонение для r = 10, 100 и 1000
и N = 10^3, 10^4, 10^5 и 10^6.

## solution

[ex.3.3.cpp](./ex.3.3.cpp)

```
$ ./ex.3.3
old: N=1000	R=10	avg=4.57	stddev=2.79519
new: N=1000	R=10	avg=4.396	stddev=2.87353
old: N=10000	R=10	avg=4.4753	stddev=2.86901
new: N=10000	R=10	avg=4.5234	stddev=2.86943
old: N=100000	R=10	avg=4.49815	stddev=2.87698
new: N=100000	R=10	avg=4.49834	stddev=2.86913
old: N=1000000	R=10	avg=4.4989	stddev=2.87353
new: N=1000000	R=10	avg=4.50002	stddev=2.87409
old: N=1000	R=100	avg=50.147	stddev=27.9563
new: N=1000	R=100	avg=49.934	stddev=28.0585
old: N=10000	R=100	avg=49.226	stddev=28.8268
new: N=10000	R=100	avg=49.5771	stddev=28.9651
old: N=100000	R=100	avg=49.4854	stddev=28.9206
new: N=100000	R=100	avg=49.4947	stddev=28.9055
old: N=1000000	R=100	avg=49.4926	stddev=28.8801
new: N=1000000	R=100	avg=49.4911	stddev=28.8639
old: N=1000	R=1000	avg=506.013	stddev=279.5
new: N=1000	R=1000	avg=502.586	stddev=292.565
old: N=10000	R=1000	avg=496.756	stddev=288.264
new: N=10000	R=1000	avg=502.183	stddev=286.098
old: N=100000	R=1000	avg=499.355	stddev=289.224
new: N=100000	R=1000	avg=501.308	stddev=288.866
old: N=1000000	R=1000	avg=499.422	stddev=288.816
new: N=1000000	R=1000	avg=499.668	stddev=288.623
```
