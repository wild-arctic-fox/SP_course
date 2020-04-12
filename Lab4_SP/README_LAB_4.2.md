Необходимо написать программу, которая может создавать 2 и более потоков (кол-во задается в командной строке). Перед запуском потоков программа заполняет для каждого потока исходный массив целочисленных значений (5-10 элементов) от 10 до 100. Каждый поток должен найти для каждого элемента массива его наибольший делитель, сохраняя полученные значения в TLS память. После нахождения всех значений он должен вывести сумму всех полученных значений и напечатать свой идентификатор. Расчет наибольшего делителя и вычисление конечной суммы должны реализовываться двумя отдельными функциями.

---
Results

---

Outputs with next args:
- 4
```
C:\Users\Olena>F:\Desktop\SP_course\Lab4_SP\Lab4.2_SP\Debug\Lab4.2_SP.exe 4
Number of threads => 4

Id => 16676
Generated array =>  40 47 23 43 72
Modyfied array =>  20 1 1 1 36
Sum => 59

Id => 14528
Generated array =>  77 46 68 16 47
Modyfied array =>  11 23 34 8 1
Sum => 77

Id => 20992
Generated array =>  25 21 29 90 44
Modyfied array =>  5 7 1 45 22
Sum => 80

Id => 10232
Generated array =>  57 61 87 57 46
Modyfied array =>  19 1 29 19 23
Sum => 91
```
- 2
```
C:\Users\Olena>F:\Desktop\SP_course\Lab4_SP\Lab4.2_SP\Debug\Lab4.2_SP.exe 2
Number of threads => 2

Id => 18212
Generated array =>  36 76 37 65 78
Modyfied array =>  18 38 1 13 39
Sum => 109

Id => 21524
Generated array =>  36 13 35 59 35
Modyfied array =>  18 1 7 1 7
Sum => 34
```
