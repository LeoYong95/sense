#!/bin/bash
#This file is used to hold variables whic collecting data



#path


data_path="collected_data" ;

export data_path ;

function get_datafile_name()
{

echo "=========================================================="
echo "Please key in name for this data file:"

read filename

export filename


}

