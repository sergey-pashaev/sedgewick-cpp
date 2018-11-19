# ex.4.41

## task

en: Using the conventions of Exercise 4.40, give a way to insert plus
signs and asterisks in the sequence E a s Y so that the sequence of
values returned by the get operations is (i) E s a Y ; (ii) Y a s E ;
(iii) a Y s E ; (iv) a s Y E ; or, in each instance, prove that no
such sequence exists.

ru: При тех же условиях, что и в упр. 4.40, расставьте в
последовательности E a s Y плюсы и звёздочки так, чтобы операции
извлечь возвращали следующую последовательность символов: (1) E s a Y,
(2) Y a s E, (3) a Y s E, (4) a s Y E; либо в каждом случае докажите,
что такая последовательность невозможна.

## solution

1. E s a Y
```
$ ./ex.4.47 E+as**Y*
E     E
+  E
a     a
s     a s
*  s  a
*  a
Y     Y
*  Y
```

2. Y a s E
```
$ ./ex.4.47 EasY+
E     E
a     E a
s     E a s
Y     Y E a s
+  Y  E a s
```
In this state it is impossible to get desired output becase 'a' lies
in the middle and we can't pop 'a' earlier than 'E' or 's'.

3. a Y s E
```
$ ./ex.4.47 Ea*sY+*+
E     E
a     E a
*  a  E
s     E s
Y     Y E s
+  Y  E s
*  s  E
+  E
```

4. a s Y E
```
$ ./ex.4.47 Ea*s*Y+*
E     E
a     E a
*  a  E
s     E s
*  s  E
Y     Y E
+  Y  E
*  E
```
