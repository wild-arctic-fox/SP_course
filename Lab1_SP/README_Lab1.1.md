Необходимо написать программу, которая бы генерировала ошибку в ходе выполнения системного вызова и выдавала системное описание данной ошибки. Вторым режимом работы данной программы должен быть вывод информации о состоянии системы. Режим запуска программы определяется ключом, передаваемым в командной строке (-e – печать ошибки, -s – печать информации о системе).
____
Results.
____

Outputs with next args:
 - **-e**
 >ERROR was generated: failed with 0x8 code<br/>
ERROR formatted message: Недостаточно ресурсов памяти для обработки этой команды.
- **-s**
 >Hardware information: <br/>
 OEM ID: 0<br/>
  Number of processors: 4<br/>
  Page size: 4096<br/>
  Processor type: 586<br/>
  Minimum application address: 10000<br/>
  Maximum application address: 7ffeffff<br/>
  Active processor mask: 15<br/>
- **without any args**
>You made a mistake !!!<br/>
Only 2 arguments available:<br/>
-e => generate error & print error<br/>
-s => print system information<br/>
  
