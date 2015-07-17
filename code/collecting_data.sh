#!/bin/bash
#
#
#shellscript testing
#filename
source code/variables.sh


#collect data from arduino
 # here is hard code ##fix me ##

#collecting data to a CSV file (Within a certain time frame)
function get_data()
{
echo "time interval for data collection : $time "
echo "data collected to : $data_path/$filename.csv "

cat /dev/ttyACM0 >$data_path/$filename.csv

}

function plot_data()
{

gnuplot<<-EOF

plot '$data_path/$filename.csv'

EOF

}
