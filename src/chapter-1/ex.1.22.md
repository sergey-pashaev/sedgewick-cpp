# ex.1.22

## task

en: Modify Program 1.4 to generate random pairs of integers between
0 and N–1 instead of reading them from standard input, and to loop
until N–1 union operations have been performed. Run your program
for N = 10^3, 10^4, 10^5, and 10^6 and print out the total number
of edges generated for each value of N.

ru: Измените программу 1.4, чтобы она генерировала случайные пары
целых чисел в диапазоне от 0 до N-1 вместо того, чтобы считывать их
из стандартного ввода, и выполняла цикл до тех пор, пока не будет
выполнено N-1 операций объединение. Выполните программу для
значений N = 10^3, 10^4, 10^5, и 10^6 и выведите общее количество
ребер, генерируемых для каждого значения N.

## solution

```
$ ./ex.1.22 1000
N = 1000 edges = 2958

$ ./ex.1.22 10000
N = 10000 edges = 42217

$ ./ex.1.22 100000
N = 100000 edges = 567222

$ ./ex.1.22 1000000
N = 1000000 edges = 7326348
```
