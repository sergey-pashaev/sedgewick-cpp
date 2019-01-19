# ex.5.19

## task

en: Draw the tree corresponding to the recursive calls that your
program from Exercise 5.18 makes when the array size is 11.

ru: Нарисуйте дерево, которое соответствует рекурсивным вызовам,
выполняемым программой из упражнения 5.18 при размере массива 11.

## solution

[ex.5.19.cpp](./ex.5.19.cpp)

```
$ ./ex.5.19
max(a, 0, 10)
  max(a, 0, 1)
    max(a, 0, 0)
    max(a, 1, 1)
  max(a, 2, 10)
    max(a, 2, 2)
    max(a, 3, 10)
      max(a, 3, 3)
      max(a, 4, 10)
        max(a, 4, 4)
        max(a, 5, 10)
          max(a, 5, 5)
          max(a, 6, 10)
            max(a, 6, 6)
            max(a, 7, 10)
              max(a, 7, 7)
              max(a, 8, 10)
                max(a, 8, 8)
                max(a, 9, 10)
                  max(a, 9, 9)
                  max(a, 10, 10)
```
