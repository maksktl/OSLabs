#!/bin/bash

if [ $# -eq 1 ]
then
  file="$1"
else
  file="file"
fi

num=$( tail -n 1 "$file" )
(( num++ ))
echo $num >> $file
