# ex.4.9

## task

en: A letter means push and an asterisk means pop in the sequence

    E A S * Y * Q U E * * * S T * * * I O * N * * *

Give the sequence of values returned by the pop operations.

ru: В последовательности

    E A S * Y * Q U E * * * S T * * * I O * N * * *

буква означает операцию втолкнуть, а звездочка - операцию
вытолкнуть. Приведите последовательность значений, возвращаемых
операциями вытолкнуть.

## solution
```
x
E     E
A     E A
S     E A S
*  S  E A
Y     E A Y
*  Y  E A
Q     E A Q
U     E A Q U
E     E A Q U E
*  E  E A Q U
*  U  E A Q
*  Q  E A
S     E A S
T     E A S T
*  T  E A S
*  S  E A
*  A  E
I     E I
O     E I O
*  O  E I
N     E I N
*  N  E I
*  I  E
*  E
```
