# ex.1.9

## task

en: Prove an upper bound on the number of machine instructions
required to process M connections on N objects using Program 1.3. You
may assume, for example, that any C++ assignment statement always
requires less than c instructions, for some fixed constant c.

ru: Определите верхнюю границу количества машинних инструкций,
требующихся для обработки M соединений N объектов при использовании
программы 1.3. Например, можно предположить, что для выполнения
оператора присваивания C++ всегда требуется выполнение менее c
инструкций, где c - некоторая фиксированная константа.

## solution
```
N - objects
M - connections
C - operations per assignment

worst case: M * (log N * 2 + 1) * C
```
