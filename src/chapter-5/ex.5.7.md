# ex.5.7

## task

en: Give the recursive depth of Euclid's algorithm when the input
values are two consecutive Fibonacci numbers (F(N) and F(N+1)).

ru: Определите глубину рекурсии алгоритма Евклида для двух
последовательных чисел Фибоначчи (F(N) и F(N+1)).

## solution

```
F(0) = 0; F(1) = 1; F(N) = F(N-1) + F(N-2), N>2

recursive call #0:
    m     n              m                n
gcd(F(N), F(N+1)  =  gcd(F(N-1) + F(N-2), F(N - 1 + 1) + F(N - 2 + 1) =

      m                n                       m                n
= gcd(F(N-1) + F(N-2), F(N) + F(N-1))  =  gcd(F(N-1) + F(N-2), 2F(N-1) + F(N-2)

Here we should make recursive call gcd(n, m % n):

    n                 m % n
gcd(2F(N-1) + F(N-2), (F(N-1) + F(N-2)) % (2F(N-1) + F(N-2)))

We see that n is greater than m by F(N-1), so result of m % n always will be m, so:

    n                 m % n                   n              m % n
gcd(2F(N-1) + F(N-2), F(N-1) + F(N-2))) = gcd(F(N) + F(N-1), F(N))

Here the number of highest Fibonacci number is decreased by 1.

recursive call #1:
    m              n             m                 n
gcd(F(N) + F(N-1), F(N))  =  gcd(2F(N-1) + F(N-2), F(N-1) + F(N-2)

Here we should make recursive call gcd(n, m % n):

    n                m % n
gcd(F(N-1) + F(N-2), (2F(N-1) + F(N-2)) % F(N-1) + F(N-2))

We see that m is greater than n by F(N-1), so result of m % n will be F(N-1), so:

    n                m % n         n     m % n
gcd(F(N-1) + F(N-2), F(N-1)) = gcd(F(N), F(N-1))

Here the number of highest Fibonacci number is decreased by 1.

So if we continue to do that, than we get:

recursive call #N-1:

    m     n
gcd(F(0), F(1))

Here we should make recursive call gcd(n, m % n):

    n     m % n              n  m % n
gcd(F(1), F(0) % F(1)) = gcd(1, 0)

recursive call #N:

    m  n
gcd(1, 0) = 1

So recursion depth is equal to N.
```
