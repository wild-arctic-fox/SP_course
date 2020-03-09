Необходимо написать программу, реализующую функцию файлового менеджера. Программа должна выдавать приглашение на ввод команды. Поддерживаемые команды:
-	Сменить директорию
-	Распечатать директорию
-	Скопировать файл
-	Создать директорию
-	Удалить файл (пустую директорию)
-	Вывести подробную информацию о файле
------
Results
------

Outputs with next args:
- pwd
```bash
----------------------------------
Name          => .
Creation time => 03-09-2020 15:08:58
Size in bytes => 0
----------------------------------
Name          => ..
Creation time => 03-09-2020 15:08:58
Size in bytes => 0
----------------------------------
Name          => Lab2.1_SP.exe
Creation time => 03-09-2020 15:09:51
Size in bytes => 38912
----------------------------------
Name          => Lab2.1_SP.ilk
Creation time => 03-09-2020 15:09:51
Size in bytes => 405412
----------------------------------
Name          => Lab2.1_SP.obj
Creation time => 03-09-2020 16:44:19
Size in bytes => 35836
----------------------------------
Name          => Lab2.1_SP.pdb
Creation time => 03-09-2020 15:09:52
Size in bytes => 593920
----------------------------------
Name          => Lab2.1_SP.tlog
Creation time => 03-09-2020 15:08:58
Size in bytes => 0
----------------------------------
Name          => Lab2.2_SP.exe
Creation time => 03-09-2020 17:04:09
Size in bytes => 46592
----------------------------------
Name          => Lab2.2_SP.ilk
Creation time => 03-09-2020 17:04:09
Size in bytes => 399716
----------------------------------
Name          => Lab2.2_SP.pdb
Creation time => 03-09-2020 17:04:10
Size in bytes => 446464
----------------------------------
Name          => vc142.idb
Creation time => 03-09-2020 15:08:58
Size in bytes => 248832
----------------------------------
Name          => vc142.pdb
Creation time => 03-09-2020 15:08:58
Size in bytes => 151552
```
- pfi current_file
```bash
File attributes: 16416
Creation time: 03-09-2020 10:30:39
Last access time: 03-09-2020 17:04:08
Last write time: 03-09-2020 15:31:58
Number of links: 1
Volume serial number: -1201947132
```
- cd
```bash
Input command:cd
Current directory name => F:\Desktop\SP_course\Lab2_SP\Lab2.1_SP\Debug
Input directory path: F:\Desktop\SP_course
Current directory name => F:\Desktop\SP_course
```
- mkdir
```bash
Directory was created
```
- rmd incorrect_path
```bash
Something went wrong(
ERROR was generated: failed with 0x20 code
ERROR formatted message: 
Процесс не может получить доступ к файлу, 
так как этот файл занят другим процессом.

```