#!/bin/bash
#
#
#shellscript testing
#filename
source data/variables.sh


#collect data from arduino
 # here is hard code ##fix me ##

#stop the collection of data

#start gnuplot
function get_data()
{
count=0 ;
if [ count=0 ]; then
{
for (( count = 0 ; count < 60 ; count++ ))
do

cat /dev/ttyACM0
sleep 1

done

} >$data_path/$filename.csv

fi

plot_data
}

function plot_data()
{

gnuplot<<-EOF

plot '$data_path/$filename.csv'

EOF

}
