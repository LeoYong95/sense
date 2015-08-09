#!/bin/bash
#Auth: Leo Yong
#
#Generating data to be ploted

source code/variables.sh

echo "Hello world"

i=0
export i


#Function that generate data....
function data_gen()
{

if [ i=0 ]; then
{
for (( i = 0; i <= 100; i++ ))

do

echo $i

done

} >$data_path/data.csv

echo "Data is collected"


fi
}

#Function to repeat the data generation process
function repeat()
{

if [ $i = 100 ]; then

$i=0
echo "process is repeating"

fi

}


