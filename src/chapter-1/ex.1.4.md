# ex.1.4

## task

en: Show the contents of the id array after each union operation when
you use the quick-find algorithm (Program 1.1) to solve the
connectivity problem for the sequence 0-2, 1-4, 2-5, 3-6, 0-4, 6-0,
and 1-3. Also give the number of times the program accesses the id
array for each input pair.

ru: Приведите содержимое массива id после выполнения каждой операции
объединение при использовании алгоритма быстрого поиска (программа
1.1) для решения задачи связности для последовательности 0-2, 1-4,
2-5, 3-6, 0-4, 6-0 и 1-3. Укажите также количество обращений программы
к массиву id для каждой вводимой пары.

## solution
```
input 0,2  id: 2 1 2 3 4 5 6 7 8 9  accesses: 15
input 1,4  id: 2 4 2 3 4 5 6 7 8 9  accesses: 15
input 2,5  id: 5 4 5 3 4 5 6 7 8 9  accesses: 17
input 3,6  id: 5 4 5 6 4 5 6 7 8 9  accesses: 15
input 0,4  id: 4 4 4 6 4 4 6 7 8 9  accesses: 19
input 6,0  id: 4 4 4 4 4 4 4 7 8 9  accesses: 17
input 1,3  id: 4 4 4 4 4 4 4 7 8 9  accesses: 2
total accesses: 100

```
