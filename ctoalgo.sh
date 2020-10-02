#!/bin/bash

Help()
{
   # Display Help
   echo
   echo "A simple bash script to convert C code to Algorithm-ish format"
   echo
   echo "Syntax: algoconv filename"
   echo
   exit
}

if [ $# == 0 ];then 
    Help 
fi

clang-format $1  | sed -e "s/}//g" \
    -e "s/{//g" \
    -e "s/#.*//" \
    -e "s/\/\/.*//g" \
    -e "s/||/or/g" \
    -e "s/if\s(\(.*\))/If \1 THEN/g" \
    -e "s/printf(\(.*\));/PRINT \1/g" \
    -e "s/puts(\(.*\));/PRINT \1/g" \
    -e "s/fgets(\([^,]*\).*)/INPUT \1/g" \
    -e "s/scanf(\(.*\).*)/INPUT \1/g" \
    -e "s/gets(\(.*\).*)/INPUT \1/g" \
    -e "s/\\\n//g" \
    -e "s/--/ Decrements /g" \
    -e "s/++/ Increments /g" \
    -e "s/for (\w*\s\(\w*\)[^;]*; \([^;]*\);.*)/FOR \1 till \2 do /g" \
    -e "s/;//g" \
    -e "/^$/d" \
    -e "s/while (\(.*\))/WHILE \1/g" \
    -e "s/return/RETURN/g" | sed -E "s/^void (.*)\(.*\)|^int (.*)\(.*\)/Start of function \1\2/g" | sed -r ':a; s%(.*)/\*.*\*/%\1%; ta; /\/\*/ !b; N; ba'
