#!/bin/bash
#
#################################################################
# Author        : Daniel S Lee                                  #
# Class         : ENGR 224                                      #
# Date          : 03/10/18 (DD/MM/YY)                           #
# Asignment #   : 1                                             #
#################################################################
# Synopsis      : Stick is a game played against a computer.    #
#                 You play by decideing how many sticks are in  #
#                 a pile, then taking turns taking 1-3 sticks   #
#                 from it, whoever (player or computer) takes   #
#                 the last stick wins.                          #
#################################################################


# Important Variables to keep in mind:
#   $turn   - 1 for user, 0 for the computer
#   $sticks - number of remaining sticks in the pile
#   


# print_sticks prints the remaining sticks in a neat format.
print_sticks () {
    echo -n "Sticks Left: ( "
    for i in $(seq $1)
    do
        echo -n "|"
        if [[ $(expr $i % 5) -eq 0 ]]
        then
            echo -n " "
        fi
    done
    # correct final extra space for formatting
    if [[ $(expr $i % 5) -ne 0 ]]
    then echo -n " "
    fi
    echo ")"
}


# ask_for_sticks prompts the user for the number of sticks to remove.
# if the user gives invalid input twice, the game ends forfited.
ask_for_sticks () {
    echo -n "<How many sticks do you want to remove?> "
    read del_sticks
    check_digit $del_sticks
    if [[ $? -ne 1 ]] || [[ $del_sticks -le 0 ]] || [[ $del_sticks -gt 3 ]]
    then
        if [[ $1 -eq 1 ]]; then exit_ungracefully; fi;
        echo "<You can only choose to remove between 1-3 sticks>"
        ask_for_sticks 1
    fi
}

# remove_sticks deletes sticks from the pile of sticks.
# it will also print the remaining sticks
remove_sticks () {
    sticks=$(expr $sticks - $del_sticks)
    print_sticks $sticks
}

# exit_ungracefully is the code that exits when two illegal inputs were given in a row.
exit_ungracefully () {
    echo "<You have given two illegal moves in a row, and thus have forfieted the game!>"
    exit 1
}


# check_digit makes sure a value is a digit.
# The result is saved in the $? variable as 1 if success and 0 if failed.
check_digit () {
    if [[ $1 -eq $1 ]] 2> /dev/null
    then return 1;
    else return 0;
    fi
}


# toggle_turn toggles the turn of the player or computer.
toggle_turn () {
    if [[ $turn -eq 0 ]]
    then turn=1;
    else turn=0;
    fi
}	


# init_game greets the user and gets the required information to start a game of stick.
init_game () {
    echo "<Welcome To Stick!>"
    local done=0
    while [[ $done -ne 1 ]]
    do
        echo -n "<How many sticks would you like to play with?> "
        read sticks
        check_digit $sticks
        # if [[ $? -ne 1 ]]
        # then echo "<Input is Not a Number, Try Again!>"; echo ""
        # elif [[ $sticks -lt 10 ]]
        # then echo "<Starting sticks must be at least 10, Try Again!>"; echo ""
        if [[ $? -eq 1 ]] && [[ $sticks -ge 10 ]]
        then done=1
        fi
    done
    done=0
    while [[ $done -ne 1 ]]
    do
        echo -n "<Who should go first?> "
        read selection
        if [[ $selection == 'c' ]]
        then
            turn=0
            done=1
        elif [[ $selection == 'u' ]]
        then
            turn=1
            done=1
        # else
        #     echo "<Invalid selection, Try Again!>"
        #     echo ""
        fi
    done
    print_sticks $sticks
}

# win_game is the logic that determines who won the game and prints the congratulatory remarks.
win_game () {
    if [[ $sticks -eq 0 ]]
    then
        if [[ $turn -eq 0 ]]
        then echo "<The winner is the Bot!>"
        else echo "<The winner is the Player!>"
        fi
        exit 0
    fi
}


# bot_turn is the logic the bot uses to take it's turn.
bot_turn () {
    local temp=$(expr $sticks % 4)
    if [[ $temp -eq 0 ]]
    then del_sticks=1
    else del_sticks=$temp
    fi
    if [[ $del_sticks -gt 1 ]]
    then echo "<The bot removed $del_sticks sticks>"
    else echo "<The bot removed 1 stick>"
    fi
}


init_game
while [[ $sticks -gt 0 ]]
do
    if [[ $turn -eq 0 ]]
    then bot_turn
    else ask_for_sticks
    fi
    remove_sticks
    win_game
    toggle_turn
done
