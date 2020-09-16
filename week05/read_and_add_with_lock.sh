#!/bin/bash

if [ $# -eq 1 ]
then
  file="$1"
else
  file="file"
fi

while ! ln "$file" "$file.lock" 2> /dev/null
do
  sleep 0.1
done

num=$( tail -n 1 "$file" )
(( num++ ))
echo $num >> $file
rm "$file.lock"