#!/bin/bash
echo 1 > out2.txt

for (( i=0; i<5; i++ ))
do
  ./read_and_add_with_lock.sh out2.txt
  ./read_and_add_with_lock.sh out2.txt
done