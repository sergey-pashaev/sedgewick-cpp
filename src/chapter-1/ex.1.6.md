# ex.1.6

###### task

en: Give the contents of the id array after each union operation for
the weighted quick-union algorithm running on the examples
corresponding to Figure 1.7 and Figure 1.8.

ru: Приведите содержимое массива id после выполнения каждой операции
объединение для алгоритма взвешенного быстрого объединения
применительно к примерам, соответствующим рис. 1.7 и 1.8.

###### solution
```
* weight indicated in brackets

figure 1.7:
input 3,4  id: 0(1) 1(1) 2(1) 3(2) 3(1) 5(1) 6(1) 7(1) 8(1) 9(1)  accesses: 3
input 4,9  id: 0(1) 1(1) 2(1) 3(3) 3(1) 5(1) 6(1) 7(1) 8(1) 3(1)  accesses: 5
input 8,0  id: 8(1) 1(1) 2(1) 3(3) 3(1) 5(1) 6(1) 7(1) 8(2) 3(1)  accesses: 3
input 2,3  id: 8(1) 1(1) 3(1) 3(4) 3(1) 5(1) 6(1) 7(1) 8(2) 3(1)  accesses: 3
input 5,6  id: 8(1) 1(1) 3(1) 3(4) 3(1) 5(2) 5(1) 7(1) 8(2) 3(1)  accesses: 3
input 5,9  id: 8(1) 1(1) 3(1) 3(6) 3(1) 3(2) 5(1) 7(1) 8(2) 3(1)  accesses: 5
input 7,3  id: 8(1) 1(1) 3(1) 3(7) 3(1) 3(2) 5(1) 3(1) 8(2) 3(1)  accesses: 3
input 8,4  id: 8(1) 1(1) 3(1) 3(9) 3(1) 3(2) 5(1) 3(1) 3(2) 3(1)  accesses: 5
input 6,1  id: 8(1) 3(1) 3(1) 3(10) 3(1) 3(2) 5(1) 3(1) 3(2) 3(1)  accesses: 7
total accesses: 37

figure 1.8:
input 0,1  id: 0(2) 0(1) 2(1) 3(1) 4(1) 5(1) 6(1) 7(1) 8(1) 9(1)  accesses: 3
input 2,3  id: 0(2) 0(1) 2(2) 2(1) 4(1) 5(1) 6(1) 7(1) 8(1) 9(1)  accesses: 3
input 4,5  id: 0(2) 0(1) 2(2) 2(1) 4(2) 4(1) 6(1) 7(1) 8(1) 9(1)  accesses: 3
input 6,7  id: 0(2) 0(1) 2(2) 2(1) 4(2) 4(1) 6(2) 6(1) 8(1) 9(1)  accesses: 3
input 8,9  id: 0(2) 0(1) 2(2) 2(1) 4(2) 4(1) 6(2) 6(1) 8(2) 8(1)  accesses: 3
input 0,2  id: 0(4) 0(1) 0(2) 2(1) 4(2) 4(1) 6(2) 6(1) 8(2) 8(1)  accesses: 3
input 4,6  id: 0(4) 0(1) 0(2) 2(1) 4(4) 4(1) 4(2) 6(1) 8(2) 8(1)  accesses: 3
input 0,4  id: 0(8) 0(1) 0(2) 2(1) 0(4) 4(1) 4(2) 6(1) 8(2) 8(1)  accesses: 3
input 6,8  id: 0(10) 0(1) 0(2) 2(1) 0(4) 4(1) 4(2) 6(1) 0(2) 8(1)  accesses: 7
total accesses: 31

```
