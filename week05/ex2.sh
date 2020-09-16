#!/bin/bash
echo 1 > out1.txt

for (( i=0; i<5; i++ ))
do
  ./read_and_add_number.sh out1.txt&
  ./read_and_add_number.sh out1.txt
done