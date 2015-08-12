#!/bin/bash
#Auth: Leo Yong
#
#collecting_data.sh will allow the data to be collected from a serial port.
#data is used to generate a graph in PNG file.

source code/variables.sh

#------------------collecting data to a CSV file (Within a certain time frame)
function get_data()
{

#------------------setup serial
sc -s 9600 ttyACM0 >$data_path/$filename.csv

exit 0;

}

#-------The processing of data needed to remove (char) <fix me>

#--------------------plot graph<fix me>
function plot_data()
{

gnuplot<<-EOF

plot '$data_path/$filename.csv'

EOF

}
