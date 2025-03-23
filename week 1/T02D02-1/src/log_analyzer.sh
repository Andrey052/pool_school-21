#! /bin/bash
if [ "$#" != 1 ]; then
    echo "Нужно ввести путь"
    exit 1
fi

if [ ! -f $1 ]; then
    echo "Файл не найден"
    exit 1
fi
touch n1.txt
touch n.txt
cut -d ' ' -f 1 $1 >> n.txt
sort n.txt > n1.txt
uniq n1.txt > n.txt
count=$(wc -l n.txt | awk '{print $1}')
rm n.txt
rm n1.txt
f=$(wc -l $1 | awk '{print $1}')
let l=$f-1
echo $f $count $l
