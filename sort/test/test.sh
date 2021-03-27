#!/bin/bash

function test_sort() {
    for ((i=$2; i<=$3; i++))
    do
        echo running $1_sort test $i
        lrun ./test $1 < data/$i > /dev/null 3> log/test_$1_$i.log
    done
}

test_sort std 10 23
test_sort quick 10 23
test_sort bubble 10 14
