# Инструкция по установке
1. скачать файлы из папки data.
2. Создать новый проект С++ - 20.
3. Перенести все файлы из data в корневую папку проекта с заменой.
4. Скомпилировать программу.
*При тестировании использовался CLion 2024.3.1.1.

# Как пользоваться
При запуске программы появится меню. Достаточно ввести номер нужной работы и следовать инструкции программы.
<img width="579" alt="Снимок экрана 2024-12-23 в 00 19 45" src="https://github.com/user-attachments/assets/dc2b740e-8e01-4797-bf5d-0725b11d045c" />


# Описание программ
# 1. "Классы. Конструкторы. Деструкторы." 
Запуск программы: При запуске программы автоматически создаются две строки: "Hello" и ее копия. Пользователю не требуется вводить данные, так как строки заданы в коде.
Вывод строк: Программа автоматически выводит обе строки на экран. Каждая строка будет выведена на новой строке без дополнительных разделителей.
Сравнение строк: Программа самостоятельно выполнит сравнение между указанными строками и выведет результат. Результат сравнения будет отображаться в числовом формате.
Завершение работы программы: Программа завершает свою работу автоматически после выполнения всех операций, таких как вывод и сравнение строк. Пользователю не нужно вводить дополнительные данные или символы для выхода.
# 2. "ИСПОЛЬЗОВАНИЕ УКАЗАТЕЛЕЙ В C++" 
Запустите программу, которая запросит у вас количество строк и столбцов матрицы. Введите целые числа, соответствующие этим параметрам. Затем программа предложит вам ввести элементы матрицы построчно. После ввода матрица будет отображена на экране. Программа автоматически проверит строки матрицы на наличие чередующихся знаков и выведет номера таких строк, если они найдутся. Обратите внимание, что программа корректно работает с числами, вводимыми без превышения допустимых размеров для выделяемой памяти. При вводе некорректных данных возможны непредсказуемые результаты.
# 3. "ДИНАМИЧЕСКОЕ СОЗДАНИЕ ЭКЗЕМПЛЯРОВ. ИСПОЛЬЗОВАНИЕ ОПЕРАЦИЙ NEW, DELETE" 
Запустите программу, которая сразу запросит у вас количество чисел, которые вы хотите ввести. Введите положительное целое число для продолжения. После этого вам будет предложено ввести сами числа, по одному за раз, через стандартный ввод. После завершения ввода программа вычислит сумму всех положительных чисел, которые находятся непосредственно после нечетных отрицательных чисел в вашем массиве. Результат будет выведен на экран. Обратите внимание, что программа корректно работает только при вводе чисел действительного типа и с разумным объемом данных, чтобы не превысить допустимую для программы оперативную память. При вводе некорректных данных или отрицательного значения в качестве размера массива программа завершена с сообщением об ошибке.
# 4. "НАСЛЕДОВАНИЕ. ВИРТУАЛЬНЫЕ ФУНКЦИИ" 
Запустите программу, и она автоматически выполнит следующие действия: Создаст два строковых объекта:
- Базового класса с содержимым "Hello".
- Производного класса с содержимым "World".
Выведет обе строки на экран: Сначала строку из базового класса. Затем строку из производного класса.Демонстрирует полиморфизм, выводя обе строки через массив указателей на базовый класс. Сравнит две строки и отобразит результат сравнения. Изменит строку в объекте производного класса на "C++". Снова выведет обе строки и выполнит повторное сравнение.
# 5. "ПЕРЕГРУЗКА ОПЕРАТОРОВ. ПЕРЕГРУЗКА ФУНКЦИЙ" 
Запустите программу, и она автоматически выполнит следующие действия:
Создаст строковый объект с содержимым "Hello".
Создаст второй строковый объект с содержимым "World" и выведет его содержимое на экран.
Создаст третий объект со строкой "Sample", изменит его содержимое на "Updated String" и отобразит результат.
Изменит третий объект, установив его строку как копию строки первого объекта ("Hello"), затем выведет её.
Создаст четвёртый объект-копию первого объекта и выведет строку его содержимого.
Создаст пятый объект путём объединения строк первого и второго объектов ("Hello" + "World") и выведет полученную строку.
Завершит выполнение.
# 6. "ШАБЛОНЫ КЛАССОВ И ФУНКЦИЙ" 
Программа позволяет обработать числовую последовательность. Она проверяет, упорядочены ли числа по убыванию, и переворачивает последовательность, если это не так.
Как работать с программой: Запустите программу — она запросит ввод типа данных:
- Введите i, если хотите работать с целыми числами (например, 1, 2, 3).
- Введите f, если хотите работать с вещественными числами (например, 1.1, 3.5, 2.5).
Следуйте инструкциям на экране:
- Укажите количество элементов в последовательности цифрами (например, 5).
- Введите числа по одному, разделяя их пробелами или нажимая Enter.
Программа проверит, упорядочена ли последовательность:
- Если элементы расположены по убыванию (например, 10, 8, 5, 2), программа сообщит об этом — изменений не потребуется.
- Если числа расположены вразнобой, программа перевернёт последовательность и выведет результат.
# 7. "ПОТОКОВЫЙ ВВОД/ВЫВОД" 
Запустите программу и следуйте инструкциям на экране. Вам будет предложено ввести набор данных в определенном порядке, который включает символ, дробное число, целое число, еще одно дробное число и заключительный символ. Вводимые дробные числа могут содержать запятую вместо точки, программа распознает их корректно и преобразует для дальнейшей обработки. Убедитесь, что вводимые значения соответствуют ожидаемым типам, иначе программа может завершиться с ошибкой. После ввода всех данных результаты будут выведены как на экран, так и в файл output.txt. Результаты включают форматированный вывод всех введенных переменных, причем дробные числа выводятся с разной степенью точности. Вы можете использовать файл output.txt для просмотра результатов после завершения программы.
