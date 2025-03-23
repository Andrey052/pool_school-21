#! /bin/bash
if [ "$#" != 3 ]; then
    echo "Нужно ввести 3 аргумента"
    exit 1
fi

if [ ! -f $1 ]; then
    echo "Файл не найден"
    exit 1
fi
if grep -q $2 $1
    then sed -i '' "s/"$2"/"$3"/g" $1
else echo "Строка $2 не найдена"
            exit 1
fi
a=$(stat -f src/$1)
b=$(stat -f %z "$1")
da=$(stat -f%c $1)
c=$(date -j -f %s "$da" "+%Y-%m-%d %H:%M")
d=$(shasum -a 256 $1 | awk '{print $1}')
ff=''$a' - '$b' - '$c' - '$d' - sha256'
echo $ff >> files.log
