# ex.4.53

## task

en: Draw a figure corresponding to Figure 4.9 for the stack ADT that
disallows duplicates using a forget-the-old-item policy.

ru: Нарисуйте рисунок, аналогичный рис. 4.9, для стэка без дубликатов,
работающего по правилу "удалять старый элемент".

## solution
```
L     L
A     L A
*  A  L
S     L S
T     L S T
I     L S T I
*  I  L S T
N     L S T N
*  N  L S T
F     L S T F
I     L S T F I
R     L S T F I R
*  R  L S T F I
S     L T F I S
T     L F I S T
*  T  L F I S
*  S  L F I
*  I  L F
O     L F O
U     L F O U
*  U  L F O
T     L F O T
*  T  L F O
*  O  L F
*  F  L
```
