/*
Author        : Daniel S Lee
Class         : ENGR 224
Date          : 15/10/18 (DD/MM/YY)
Asignment #   : 2

Synopsis      : Stick is a game played against a computer.
                You play by decideing how many sticks are in
                a pile, then taking turns taking 1-3 sticks
                from it, whoever (player or computer) takes
                the last stick wins.
*/
#include <stdio.h>
#include <stdlib.h>

int   initGame(int, char**);
int   botChoice(int);
int   playerChoice();
void  winGame(int);
char* remainingSticks(char*, int);
char* strcat(char*, char*);

int main(int argc, char** argv) {
    printf("<Welcome To Stick!>\n");
    int  botTurn = 0;
    char string[160];
    int  sticks = initGame(argc, argv);
    printf(remainingSticks(string, sticks));
    while (sticks > 0) {
        if (botTurn) {
            sticks -= botChoice(sticks);
            printf(remainingSticks(string, sticks));
            botTurn = 0;
        } else {
            sticks -= playerChoice();
            printf(remainingSticks(string, sticks));
            botTurn = 1;
        }
    }
    winGame(botTurn);
    return 1;
}

// initGame prompts the player for the starting sticks and does input checking
int initGame(int argc, char** argv) {
    char buf[64];
    buf[0]  = '\0';
    char* p = buf;
    int   r;
    switch (argc) {
        case 1:
            printf("<How many sticks would you like to play with?> ");
            fgets(p, 63, stdin);
            break;
        case 2:
            p = argv[1];
            break;
        default:
            printf("Error: Too many arguments!\n");
            exit(1);
    }
    int chk = sscanf(p, "%d", &r);
    if (chk != 1) {
        printf("Error: Bad input!\n");
        exit(1);
    }
    if (r <= 10) {
        printf("Error: Starting Sticks must be over 10!\n");
        exit(1);
    }
    if (r > 100) {
        printf("Error: Too boring of a game! (too many sticks)\n");
        exit(1);
    }
    return r;
}

// botChoice is the logic that decides how many sticks to remove
int botChoice(int s) {
    int r = s % 4;
    switch (r) {
        case 3:
        case 2:
            printf("<The bot removed %d sticks>\n", r);
            return r;
        default:
            printf("<The bot removed 1 stick>\n");
            return 1;
    }
}

// playerChoice requests a number of sticks to remove for the player's turn.
// It will not fail the player on failed attempts and just keep retrying.
int playerChoice() {
    char in[100];
    int  done = 0;
    int  r, chk;
    while (!done) {
        printf("<How many sticks do you want to remove?> ");
        fgets(in, 99, stdin);
        chk = sscanf(in, "%d", &r);
        if (chk && (r >= 0) && (r < 4)) {
            done = 1;
        } else {
            printf("<You can only choose to remove between 1-3 sticks>\n");
        }
    }
    return r;
}

// winGame ends the game and announces the winner.
// The logic is slightly misleading because the turns are flopped after the
// while loop exits.
void winGame(int botTurn) {
    char* winner;
    if (botTurn) {
        winner = "Player";
    } else {
        winner = "Bot";
    }
    printf("<The winner is the %s!>\n", winner);
}

// remainingSticks takes a number of sticks and returns a formatted string.
char* remainingSticks(char* buf, int q) {
    buf[0]  = '\0';
    char* p = buf;

    p = strcat(p, "Sticks Left: (");
    for (int i = 0; i < q; i++) {
        if (!(i % 5)) { p = strcat(p, " "); }
        p = strcat(p, "|");
    }
    p = strcat(p, " )\n");

    return buf;
}

// strcat cats information into a buffer blindly (buffer overflow danger)
char* strcat(char* dst, char* src) {
    while (*dst) dst++;
    while (*dst++ = *src++) {};
    return --dst;
}