#!/bin/bash

echo "Enter the name of the executable:"
read executable

valgrind --tool=memcheck --leak-check=yes --log-file=valgrind.log $executable 2>> valgrind.log
error_lines=$(grep -P 'errors from(?! 0 contexts)' valgrind.log)
error_prefixes=$(echo "$error_lines" | awk '{print substr($0, 1, 9)}' | sort -u)
for prefix in $error_prefixes; do
  grep "^$prefix" valgrind.log
done

echo
echo
echo 

find . -name "*.c" -o -name "*.h" | xargs clang-format -n -style=google