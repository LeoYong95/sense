#!/bin/bash
#Auth: Leo Yong
#
#This file is used to hold variables whic collecting data



#-------------------universal variables
data_path="data" ;


export data_path ;

#------------------get name for data file
function get_datafile_name()
{

echo "=========================================================="
echo "Please key in name for this data file:"

read filename

export filename


}

#-----------------get duration for data collection
function get_data_time()
{
echo "========================================================="
echo "What is the time interval of data collection?? (in seconds)"

read time

export time

}
