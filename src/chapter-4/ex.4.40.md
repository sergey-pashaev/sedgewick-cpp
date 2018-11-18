# ex.4.40

## task

en: An uppercase letter means put at the beginning, a lowercase letter
means put at the end, a plus sign means get from the beginning, and an
asterisk means get from the end in the sequence

    E A s + Y + Q U E * * + s t + * + I O * n + + *

Give the sequence of values returned by the get operations when this
sequence of operations is performed on an initially empty deque.

ru: В последовательности

    E A s + Y + Q U E * * + s t + * + I O * n + + *

прописные буквы означают операцию занести в начале дэка, строчные
буквы - операцию занести в конце дека, знак плюс означает операцию
извлечь в начале, а звездочка - операцию извлечь в конце. Найдите
последовательность значений, возвращаемых операциями извлечь, если эта
последовательность операций выполняется над первоначально пустым
дэком.

## solution

[ex.4.40.cpp](./ex.4.40.cpp)

```
$ ./ex.4.40
A
Y
s
E
E
U
t
Q
s
O
I
n
```
