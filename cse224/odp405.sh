#!/bin/bash
#

if $1
then
	echo $(eval $1*2)
else
	echo -n ">"
fi
