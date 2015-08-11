#!/bin/bash
#Auth: Leo Yong
#
#collecting_data.sh will allow the data to be collected from a serial port.
#data is used to generate a graph in PNG file.

source code/variables.sh

#collecting data to a CSV file (Within a certain time frame)
function get_data()
{
#report
echo "time interval for data collection : $time "
echo "data collected to : $data_path/$filename.csv "

#setting up Serial Port
stty -F /dev/ttyACM0 cr0

time_int=$(($time))
#start a timer
end_time=$((`date +%s` + $time_int));

while [ "$end_time" -ne `date +%s` ] ;
do

cat /dev/ttyACM0

#transfer data to a csv file
done >$data_path/$filename.csv


#call when time is up
if [ "$end_time" -eq `date +%s` ]
then

echo "The end of collecting data"

fi


}
# plot graph
function plot_data()
{

gnuplot<<-EOF

plot '$data_path/$filename.csv'

EOF

}
