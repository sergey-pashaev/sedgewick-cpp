# ex.5.8

## task

en: Give the figure corresponding to Figure 5.3 for the result of
recursive prefix-expression evaluation for the input + * * 12 12 12
144.

ru: Приведите рисунок, соответствующий рис. 5.3, для результата
вычисления префиксного выражения + * * 12 12 12 144.

## solution

[ex.5.8.cpp](./ex.5.8.cpp)

```
$ ./ex.5.8
+ * * 12 12 12 144
eval() + * * 12 12 12 144
  eval() * * 12 12 12
    eval() * 12 12
      eval() 12
      eval() 12
      return 144 = 12*12
    eval() 12
    return 1728 = 144*12
  eval() 144
  return 1872 = 1728+144
1872
```
