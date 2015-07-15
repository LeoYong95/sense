#!/bin/bash

#Generating data to be ploted
echo "Hello world"

i=0

export i

function data_gen()
{
if [ i=0 ]; then
{
for (( i = 0; i <= 101; i++ ))

do

echo "$i"

done
} >data.csv

fi
}

function repeat()
{

if [ i=100 ]; then

i=0

data_gen

echo "process is repeating"

fi

}

data_gen

repeat
