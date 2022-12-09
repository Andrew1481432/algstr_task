# algstr_task
<parent align="center">
	<b>Практики по предмету структуры и алгоритмы обработки данных(СИАОД)</b>
</parent>
Здесь опубликованы практические задания с предмета СИАОД.

Во втором семестре практических работ 7 штук и они связаны с сортировками и списками (Преподователь: Рысин М.Л.)
<br>
В третьем семестре работ 7 штук и они связаны с битовыми операциями, хешированием и деревьями (Преподователь: Туманова М.Б.)
<br>
### Работы по 2-ому семестру:
<br>
1. Оценка сложности и определение эффективности алгоритма.<br>

>Данная работа была разделена на два варианта:

>В первом варианте надо было определить эффективный алгоритм из двух предложенных, используя оценку теоретической сложности каждого из алгоритмов.

>Во втором варианте мне попалась задача `Найти максимальный элемент в части матрицы, расположенной над главной диагональю.`, где надо было определить эффективноcть алгоритма(определить инвариант, доказать корректность циклов в алгоритме, определить вычислительную сложность алгоритма на основе теоретического подхода)
2. Эмпирический анализ алгоритмов сортировки
> Данная работа имела три задания:

> В первом задании мне попался `алгоритм простого обмена(пузырек)` и задание заключалось в оценке зависимости времени выполнения алгоритма на массиве, заполненном случайными числами.

> Во втором задании надо оценить вычислительную сложность алгоритма простой сортировки в наихудшем и наилучшем случаях.

> В третьем задании мне попалась `алгоритм простой вставки`, который надо было сравнить с алгоритмом первого задания.
3. Асимптотический анализ эффективности на примерах алгоритмов
   сортировки
> Данная работа была разделена на два задания, здесь надо было разработать алгоритмы сортировки, определенные вариантом. Провести анализ вычислительной и емкостной сложности алгоритма на массивах, заполненных случайно. Определить наиболее эффективный алгоритм 

> В первом задании надо было разработать алгоритм ускоренной сортировки(Усовершенствованный алгоритм) `Шелла со смещениями
Р. Седжвика`.
 
> В третьем задании надо было разработать `Быстрая сортировка (Хоара)`.
4. Алгоритмы внешних сортировок
> В данной работе требовалось реализовать два алгоритма `Алгоритм сортировки прямого слияния для файлов` и `Алгоритм естественного слияния, оптимизированный для файлов`. Работа делалась по варианту сортировать нужно было структуру. Структура под названием товар в себя включала наименование товара, Страна импортирующая товар, Количество(в штуках). Ключевое поле структры Страна импортирующая товар.
5. Однонаправленный динамический список
6. Двунаправленные динамические списки
7. Рекурсивные алгоритмы и их реализация

### Работы по 3-ему семестру:
1. Поразрядные операции и их применение
>##### Требования к выполнению задания

> 1. Разработать программу, которая продемонстрирует выполнение
> упражнений варианта. Результаты выполнения упражнения выводить на
> монитор.
> Требования к упражнениям (номер требования определяет номер
> упражнения в таблице)

> 1) Определить переменную целого типа, присвоить ей значение, используя
> константу в шестнадцатеричной системе счисления.
> Разработать оператор присваивания и его выражение, которое установит
> заданные в задании биты исходного значения переменной в значение 1,
> используя соответствующую маску и поразрядную операцию.

> 2) Определить переменную целого типа.
> Разработать оператор присваивания и его выражение, которое обнуляет
> заданные в задании биты исходного значения переменной, используя
> соответствующую маску и поразрядную операцию. Значение в
> переменную вводится с клавиатуры.

> 3) Определить переменную целого типа.
> Разработать оператор присваивания и выражение, которое умножает
> значение переменной на число, указанное в третьем столбце варианта,
> используя соответствующую поразрядную операцию. Изменяемое число
> вводится с клавиатуры.

> 4) Определить переменную целого типа.
> Разработать оператор присваивания и выражение, которое делит значение
> переменной на число, указанное в четвертом столбце варианта, используя
> соответствующую поразрядную операцию. Изменяемое число вводится с
> клавиатуры.

> 5) Определить переменную целого типа.
> Разработать оператор присваивания и выражение, в котором
> используются только поразрядные операции. В выражении используется
> маска – переменная. Маска может быть инициализирована единицей в
> младшем разряде (вар 1) или единицей в старшем разряде (вар 2).
> Изменяемое число вводится с клавиатуры.

#### Мой вариант под номером 2

| № | 1 Номер бита  | 2 Номер бита       | 3 множитель | 4 делитель | 5 Задание для выражения                           |
| ------- |:--------------|:-------------------|:------------|:-----------|---------------------------------------------------|
| 2 | Три старших   | 12-ый, 14-ый, 3-ий | 4           | 4          | Установить n-ый бит в 1, используя маску пункта 2 |

2. Хеширование: прямой доступ к данным (цепное хеширование)
>#### В моем вариане надо было реализовать метод хеширования `Цепное хеширование`
3. Поиск образца в тесте.

#### Мой вариант под номером 1

| № задачи | Задачи                                                                                       |
|----------|:---------------------------------------------------------------------------------------------|
| 1        | Линейный поиск первого вхождения подстроки в строку                                          |
| 2        | Используя алгоритм Бойера-Мура-Хорспула, найти последнее вхождение подстроки в строку.       |

4. Бинарное дерево поиска. AVL дерево.
>#### В моем вариане надо было реализовать `красно-черное дерево`
5. Алгоритмы работы с графами.
>#### В моем вариане надо было реализовать построение остовного дерева алгоритмом `Крускала`
6. Кодирование и сжатие данных методами без потерь.
>#### Надо было реализовать алгоритм сжатия `Шеннона – Фано` и `Хаффмана`
7. Алгоритмические стратегии. Разработка и программная реализация задач с применением метода сокращения числа переборов.
>#### Надо подсчитать `число последовательностей нулей и единиц длины n, в которых не встречаются две идущие подряд единицы.`