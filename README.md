# Основные команды для работы с файлами и директориями
### 1. ls — список файлов и директорий.
ls -l - Подробный список<br>
ls -a - Показать скрытые файлы<br>
### 2. cd — сменить текущую директорию.
cd ~   Перейти в домашнюю директорию<br>
cd ..   Перейти на уровень выше<br>
### 3. pwd — показать текущую директорию.
pwd
### 4. mkdir — создать директорию.
mkdir mydir   Создать директорию "mydir"<br>
mkdir -p dir1/dir2   Создать вложенные директории
### 5. rm — удалить файл или директорию.
rm file.txt   Удалить файл<br>
rm -r mydir  Удалить директорию рекурсивно<br>
rm -f file.txt  Удалить файл без подтверждения<br>
### 6. cp — копировать файл или директорию.
cp file.txt file_copy.txt  Копировать файл<br>
cp -r dir1 dir2  Копировать директорию рекурсивно<br>
### 7. mv — переместить или переименовать файл/директорию.
mv file.txt newfile.txt  Переименовать файл<br>
mv file.txt /path/to/directory  Переместить файл
### 8. cat — вывести содержимое файла.
cat file.txt
### 9. chmod — изменить права доступа к файлу или директории.
chmod +x script.sh  Сделать файл исполняемым

## Команды для работы с процессами
### 1. ps — показать запущенные процессы.
ps aux  Показать все процессы
### 2. top / htop — мониторинг процессов в реальном времени.
top
htop
### 3. kill — завершить процесс.
kill 1234   Завершить процесс с PID 1234
kill -9 1234   Принудительно завершить процесс
### 4. pkill — завершить процесс по имени.
pkill process_name

## Создание новой ветки
### 1. Чтобы создать новую ветку, используйте команду:
git branch <имя_ветки>
### 2. Создание ветки и переключение на неё
Чтобы сразу создать ветку и переключиться на неё, используйте команду:<br>
git checkout -b <имя_ветки>
### 3. Просмотр списка веток
Чтобы увидеть список всех веток в репозитории, используйте команду:<br>
git branch
Текущая ветка будет выделена звездочкой (*).
### 5. Переключение на существующую ветку
Если вы хотите переключиться на уже существующую ветку, используйте команду:<br>
git checkout <имя_ветки>
### 6. Удаление ветки
Если ветка больше не нужна, её можно удалить:<br>
git branch -d <имя_ветки>
### 7. Отправка ветки на удаленный репозиторий
После создания ветки её можно отправить на удаленный репозиторий:<br>
git push origin <имя_ветки><br>
<имя_ветки> - например develop

## Создание нового SSH-ключа
### 1. Если у вас нет SSH-ключа:
ssh-keygen
ssh-keygen /.ssh/id_ed25519
### 2. Копирование SSH-ключа
Скопируйте содержимое вашего публичного ключа в буфер обмена:<br>
cat ~/.ssh/id_ed25519.pub

## Как протестировать программу:
### 1. Скомпилируйте программу:
gcc -Wall -Werror -Wextra <имя файла> -o 1 <br>
<имя файла> - например arithmetic.c
### 2. Если компиляция прошла успешно, запустите программу:
./1

## Форматирование исходного кода с заданным стилем:
### 1. Запустите clang-format -i для автоматического форматирования файла:
clang-format -i <имя файла>
### 2. Проверьте, что файл отформатирован:
clang-format -n <имя файла><br>
<имя файла> - например arithmetic.c<br>
Если вывод пустой, значит, код соответствует стилю.

Не забываем ставить звездочку! &#11088;
