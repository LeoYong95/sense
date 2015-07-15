#!/bin/bash
#
#
#shellscript testing

#filename

filename = date +%D

echo filename

export filename
#start the collection of data

#display timer

#collect data from arduino
cat /dev/ttyACM0 > ${filename}.csv # here is hard code ##fix me ##

#stop the collection of data

#start gnuplot

gnuplot<<-EOF

set terminal png
set output '${filename}.png'
plot '${filename}.csv';
exit

EOF


