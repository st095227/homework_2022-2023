#!/bin/bash

cd /
cd /mnt/d/homeworkPR/homework_2022-2023/2022.12.11-homework-11_Bash/exeF
#pwd
#ls -l
./1.exe &
./2.exe &
./3.exe &
./4.exe &
./5.exe &
wait
if cmp res1.txt output1.txt
then echo "файлы 1 равны"
fi

if cmp res2.txt output2.txt
then echo "файлы 2 равны"
fi

if cmp res3.txt output3.txt
then echo "файлы 3 равны"
fi

if cmp res4.txt output4.txt
then echo "файлы 4 равны"
fi

if cmp res5.txt output5.txt
then echo "файлы 5 равны"
fi
echo Finished