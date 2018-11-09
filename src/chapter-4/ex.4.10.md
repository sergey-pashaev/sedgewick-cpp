# ex.4.10

## task

en: Using the conventions of Exercise 4.9, give a way to insert
asterisks in the sequence EASY so that the sequence of values returned
by the pop operations is (i) EASY; (ii) YSAE; (iii) ASYE; (iv) AYES;
or, in each instance, prove that no such sequence exists.

ru: Используя те же соглашения, что и в упражнении 4.9, вставьте
звёздочки в последовательность EASY таким образом, чтобы
последовательность значений, возвращаемых операциями вытолкнуть, была
следующей: (1) EASY; (2) YSAE; (3) ASYE; (4) AYES; либо докажите, что
такая последовательность невозможна.

## solution

1.
```
E     E
*  E
A     A
*  A
S     S
*  S
Y     Y
*  Y
```

2.
```
E     E
A     E A
S     E A S
Y     E A S Y
*  Y  E A S
*  S  E A
*  A  E
*  E
```

3.
```
E     E
A     E A
*  A  E
S     E S
*  S  E
Y     E Y
*  Y  E
*  E
```

4.
```
E     E
A     E A
*  A  E
S     E S
Y     E S Y
*  Y  E S
```

It is impossible to pop E from stack earlier than S, because its
violate LIFO (Last-In First-Out) principle. E - was added before S, so
it is impossible to get it after S.
