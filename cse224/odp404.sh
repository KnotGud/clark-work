#!/bin/bash

i=$2
while [[ $i -gt 0 ]]
do
    echo $1
    i=$(expr $i - 1)
done