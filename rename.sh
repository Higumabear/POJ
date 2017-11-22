#!/bin/bash

for dirname in `ls -1r`
do
    for file in `ls ${dirname}/*`
    do
	if [ `echo ${file} | grep "AC"` ]; then
	    extension=${file##*.}
	    if [ "${extension}" = "cc" -o "${extension}" = "cpp" ];
		then
		echo "${dirname}.cpp"
		cp ${file} "${dirname}.cpp"
	    elif [ "${extension}" = "java" ];
		then
		echo "${dirname}.java"
		cp ${file} "${dirname}.java"
	    fi
	fi
    done
done
