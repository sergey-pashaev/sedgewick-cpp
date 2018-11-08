# ex.3.50

###### task

en: Run empirical studies comparing the running times of the
memory-allocation functions in Program 3.14 with new and delete(see
Exercise 3.49) for Program 3.13 with M = 2 and N = 10^3, 10^4, 10^5,
and 10^6.

ru: Эмпирически сравните время выполнения функций распределения памяти
из программы 3.14 с операторами new и delete (см. упражнение 3.49) для
программы 3.13 при M = 2 и N = 10^3, 10^4, 10^5 и 10^6.

###### solution
```
$ ./ex.3.50.sh
freelist=0m0.006s new=0m0.004s N=1000 M=2
freelist=0m0.004s new=0m0.008s N=10000 M=2
freelist=0m0.008s new=0m0.017s N=100000 M=2
freelist=0m0.061s new=0m0.122s N=1000000 M=2
```
