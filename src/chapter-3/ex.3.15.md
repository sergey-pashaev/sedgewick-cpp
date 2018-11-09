# ex.3.15

## task

en: Empirically determine the effect of removing the test of a[i] from
the inner loop of Program 3.5, for N = 10^3, 10^4, 10^5, and 10^6, and
explain the effect that you observe.

ru: Эмпирически определите эффект удаления проверки a[i] из
внутреннего цикла программы 3.5 для N = 10^3, 10^4, 10^5, 10^6 и
объясните его.

## solution

```
$ ./ex.3.15.sh
w/ check (2254893) vs w/o check (2276225) for N=1000 is .94603158553421381800% change
w/ check (3033418) vs w/o check (3489428) for N=10000 is 15.03287710430939619900% change
w/ check (11369415) vs w/o check (18515477) for N=100000 is 62.85338339747471615700% change
w/ check (99300801) vs w/o check (197770832) for N=1000000 is 99.16338036387037804400% change
```

Well, without check in inner loop we do a lot of unnecessary array
accesses, which results in poor performance against version with
check.
