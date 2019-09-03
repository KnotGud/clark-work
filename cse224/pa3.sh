#!/bin/bash
#
#################################################################
# Author        : Daniel S Lee                                  #
# Class         : ENGR 224                                      #
# Date          : 01/11/18 (DD/MM/YY)                           #
# Asignment #   : 3                                             #
#################################################################
# Synopsis      : HighLow is a game played against a computer.  #
#                 You play by decideing a number from 1 and any #
#                 number, then having the computer attempt to   #
#                 guess your number. You respond by saying if   #
#                 the guess whas high, low, or correct.         #
#################################################################

init_game() {
    echo "<Welcome to HighLow!>"
    echo "<Please think of a number between 1 and $max>"
    echo -n "<Hit any key when you have your number>"
    read -n 1
    echo
}

calculate_num() {
    guess=$(expr '(' $min + $max ')' / 2)
}

check_high() {
    if [[ $guess -eq $min ]]
    then
        echo "<You made a mistake in your guessing!>"
        exit 1
    fi
}

check_low() {
    if [[ $(expr $min + 1) -gt $guess || $guess -eq $max ]]
    then
        echo "<You made a mistake in your guessing!>"
        exit 1
    fi
}


process_resp() {
    if [[ $resp == 'h' ]]
    then
        check_high
        count=$(expr $count + 1)
        max=$guess
    elif [[ $resp == 'l' ]]
    then
        check_low
        count=$(expr $count + 1)
        min=$(expr $guess + 1)
    elif [[ $resp == 'c' ]]
    then
        count=$(expr $count + 1)
        done=1
    else echo "<You can ony reply with (h)igh, (l)ow, or (c)orrect!>"
    fi
}


if [[ $# -ne 1 ]]
then max=100
else max=$1
fi
min=1
init_game
done=0
while [[ $done -ne 1 ]]
do
    calculate_num
    echo -n "<Is your number $guess?> "
    read -n 1 resp
    echo
    process_resp
done
echo "<It took $count attempts to find your number!>"