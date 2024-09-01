#!/bin/bash

for var in -b -e -n -s -t
  do 
  cat $var test_cat.txt > cat.txt
  ./s21_cat $var test_cat.txt > mycat.txt
  if diff cat.txt mycat.txt > diffres.txt
  then
  echo for $var SUCCESS
  else 
  echo for $var FAIL
  fi
  done
