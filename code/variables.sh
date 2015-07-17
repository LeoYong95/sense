#!/bin/bash
#This file is used to hold variables whic collecting data



#path


data_path="data" ;

export data_path ;

function get_datafile_name()
{

echo "=========================================================="
echo "Please key in name for this data file:"

read filename

export filename

get_data_time
}

function get_data_time()
{
echo "========================================================="
echo "What is the time interval of data collection?? (in seconds)"

read time

export time

}
