# EXAM_05_04. Removing repetitions

The russian version of the task can be found in the repository.

## Task

| Exam_05_04                  |                                 |
| --------------------------- | ------------------------------- |
| Level:                      | 3.                              |
| Topics:                     | Dynamic arrays.                 |
| Directory for the solution: | src/                            |
| Solution files:             | main.c                          |
| Input data:                 | Standard input stream (stdin)   |
| Output data:                | Standart output stream (stdout) |

Написать программу, производящую удаление повторяющихся элементов последовательности, состоящей из целых неотрицательных чисел. Последовательность задается на стандартном потоке ввода stdin, элементы последовательности разделены между собой пробелами, концом последовательности является число -1, которое обозначает конец последовательности и не является ее злементом. Вывести элементы результирующей последовательности, разделенные между собой пробелами, на стандартный поток вывода stdout. В конце ответа не должно быть переноса на новую строку. Проверить на валидность введенные данные. В случае любой ошибки выводить "n/a".

> **Note:** Порядок вывода элементов в результирующей последовательности определяется порядком первых вхождений соответствующих значений в первоначальной последовательности.

> последовательность может быть любого размера.

## Examples

| Input          | Output  |
| -------------- | ------- |
| 1 1 2 2 3 -1   | 1 2 3   |
| 1 2 1 3 1 4 -1 | 1 2 3 4 |
| -1             |         |

> **Attention:** We kindly remind you that the procedure for testing your program includes an analysis of the code style. Please look in the "materials /" folder. Also, be sure to check your program for memory leaks.
