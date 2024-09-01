#!/bin/bash

for var in -e -i -v -c -l -n -h
  do
    grep $var you test_1_grep.txt test_2_grep.txt > grep.txt
    ./s21_grep $var you test_1_grep.txt test_2_grep.txt > mygrep.txt
    if diff grep.txt mygrep.txt > diffres.txt
    then
    echo for $var SUCCESS
    else 
    echo for $var FAIL
    fi
  done


grep -s you test_1_grep.txt test_1645_grep.txt > grep.txt
./s21_grep -s you test_1_grep.txt test_1645_grep.txt > mygrep.txt
if diff grep.txt mygrep.txt > diffres.txt
  then
  echo for -s SUCCESS
  else 
  echo for -s FAIL
fi

grep -f file_template.txt test_1_grep.txt > grep.txt
./s21_grep -f file_template.txt test_1_grep.txt > mygrep.txt
if diff grep.txt mygrep.txt > diffres.txt
  then
  echo for -f SUCCESS
  else 
  echo for -f FAIL
fi
