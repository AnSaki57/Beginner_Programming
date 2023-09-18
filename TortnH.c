/*
    There are 100 squares, and a Tortoise and hare 
    contest to reach square 100 from square 1
    Evry one turn, make one decision:-

    Tortoise:-
    4+ 50%  (20-8+3=15)
    4- 20%
    1+ 30+

    Hare:-
    0+ 20%  (0+22-10+3-2=13)
    11+20%
    10-10%
    1+ 30%
    1- 20%

    (use "scanf("1\n");" to get next turn by
    pressing enter key)

    If position of animal < 1, make it 1
    > 100, make it 100

    For each turn, print 100 lines showing T for Tortoise,
    H for hare

    Initialise Tort_posn and Hare_posn
    Explain rules and conditions for winning
    Print race start
*/

//getc(stdin);   (Helps take ENTER key from user to proceed)

/*
    ----------------------------------------------------------------------------------------------------
    T
    ----------------------------------------------------------------------------------------------------
    H
    ----------------------------------------------------------------------------------------------------

    (Racetrack)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    //Starting comments
    printf("[Press ENTER to continue, at any time]");
    getc(stdin);

    printf("\nWelcome to Tortoise vs Hare! Take your bets, and be ready!");
    getc(stdin);
    printf("The racetrack is 100m long, and our contestants start off at 1!");
    getc(stdin);

    puts("\n----------------------------------------------------------------------------------------------------");
    puts("T");
    puts("----------------------------------------------------------------------------------------------------");
    puts("H");
    puts("----------------------------------------------------------------------------------------------------");
    puts("T = Tortoise");
    puts("H = Hare\n");
    printf("[ENTER to continue]");
    getc(stdin);

    puts("\nStart the race?");
    printf("[ENTER to continue]");
    getc(stdin);

    puts("\n\n\n\n");

    //Initialise vars
    int tort_posn;
    int hare_posn;

    //Randomise moves
    srand(time(0));
    int move;

    //For each turn
    while (tort_posn < 100 && hare_posn < 100) {
        //Tortoise makes a move
        move = rand() % 10;
        if (move < 5) {
            tort_posn += 4;
        } else if (move == 5 || move == 6) {
            tort_posn -= 4;
        } else {
            tort_posn++;
        }

        //Hare makes a move
        move = rand() % 10; 
        if (move < 2) {
        } else if (move >= 2 && move < 4) {
            hare_posn += 11;
        } else if (move == 4) {
            hare_posn -= 10;
        } else if (move > 4 && move < 8) {
            hare_posn++;
        } else {
            hare_posn--;
        }

        //To ensure tortoise/hare don't go off-track (<1,>100)
        if (tort_posn < 1) {
            tort_posn = 1;
        }
        if (tort_posn > 100) {
            tort_posn = 100;
        }
        if (hare_posn < 1) {
            hare_posn = 1;
        }
        if (hare_posn > 100) {
            hare_posn = 100;
        }

        //Print track using for loops
        printf("----------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < tort_posn; i++) {
            printf(" ");
        }
        printf("T\n");
        printf("----------------------------------------------------------------------------------------------------\n");
        for (int j = 0; j < hare_posn; j++) {
            printf(" ");
        }
        printf("H\n");
        printf("----------------------------------------------------------------------------------------------------\n\n\n");
        
        //printf("%d %d\n", tort_posn, hare_posn);

        //Sleep for 0.265 seconds (265,000 microseconds)
        usleep(265000);
    }

    //Declare winner
    if (tort_posn == 100) {
        printf("TORTOISE WINS!!!\nVICTORY FOR THE UNDERDOG!\n");
    } else {
        printf("HARE WINS!(Nobody expected that)\n");
    }
}