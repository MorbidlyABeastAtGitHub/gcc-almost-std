#!/bin/bash
if [ "$EUID" -ne 0 ]
then
    echo "Please run this installation script as root or with sudo"
    exit 2
fi
input="Stuff"
read -p "(Y/n) Confirm installation?: " input
if [ $input = "Y" ] || [ $input = "y" ]
then
	sudo cp $(pwd)/library/* /usr/include
else
 echo "No install"
fi
exit 0
	
