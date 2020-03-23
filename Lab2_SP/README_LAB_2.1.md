Написать программу, реализующую произвольный доступ к записям в файле двумя способами: с помощью указателя файла (file pointer).
Структура записи:
-	номер записи;
-	время создания записи (в формате FILETYME);
-	текстовая строка заданной длины (80 символов);
-	счетчик, показывающий, сколько раз запись изменялась.

Запись может быть пустая (инициализирована нулями).
В заголовке файла хранить количество непустых записей в файле и размер файла. Общее количество записей в файле задается из командной строки. Пользователь должен иметь возможность удалять и модифицировать существующие записи, обращаясь к ним по номеру. Интерфейс с пользователем реализуется на усмотрение студента.

----
Results

----

Output with next args:
- 3 pr
```
Input command :
rm = > delete record
mf = > modify record
pr = > print records
pr
Header information
File size in bytes : 308
Not empty record count : 0
Id -> 0 Counter -> 0    Text->Creation time -> 03 - 23 - 2020
Id -> 1 Counter -> 0    Text->Creation time -> 03 - 23 - 2020
Id -> 2 Counter -> 0    Text->Creation time -> 03 - 23 - 2020
```
- mf
```
mf
Input id to modify : 1
Input text(80 symbols without space) : walking_dead
Input command :
rm = > delete record
mf = > modify record
pr = > print records
pr
Header information
File size in bytes : 308
Not empty record count : 1
Id -> 0 Counter -> 0    Text->Creation time -> 03 - 23 - 2020
Id -> 1 Counter -> 1    Text->walking_dead    Creation time -> 03 - 23 - 2020
Id -> 2 Counter -> 0    Text->Creation time -> 03 - 23 - 2020
```
- rm
```
rm
Input id to modify : 1
Input command :
rm = > delete record
mf = > modify record
pr = > print records
pr
Header information
File size in bytes : 308
Not empty record count : 0
Id -> 0 Counter -> 0    Text->Creation time -> 03 - 23 - 2020
Id -> 1 Counter -> 0    Text->Creation time -> 03 - 23 - 2020
Id -> 2 Counter -> 0    Text->Creation time -> 03 - 23 - 2020
```
