/*
    (Version 1.0)
    Idle clicker where the objective is to enter a char and click enter,
    to perform various functions, like going to the next turn, buying
    capital-producing things, etc.

    A while loop runs endlessly unless the player wants to quit,
    and '0' makes 1 month pass while player can collect profilts
    from all the shops they own.
    '1' character buys the least expensive shop (if player can 
    afford it), '2' buys the second-least expensive, and so on.
*/
/*
    Display board
    
    Things you can buy:-
    (Tier 1)
    Name                   Cost       Call code  Production per turn
    Lemonade stand         $1000      1          $50
    V.Small bakery         $2500      2          $100
    Small Tatoo shop       $4500      3          $250
    V.Small Hardware store $7950      4          $390
    V.Small Restaurant     $20,000    5          $900
    V.Small Manga Store    $42,000    6          $2250

    (Tier 2)
    Name                 Cost         Call code  Production per turn
    Small bakery         $200,000     1          $12,000
    V.Small software co. $450,000     2          $25,000
    Tatoo shop           $800,000     3          $36,500
*/

/*
    Assets owned

    Things you own:-
    Name                   Quantity        Income
    (Show only below income $400){
    Universal Basic Income -               $50
    }
    Lemonade stand         assets_count[0] $assets_count[0] * income[0]
    Small bakery           assets_count[1] $assets_count[1] * income[1] 
    ..
*/

/*
    Commands board

    Commands you can use:-
    Command   Use
    h         Open help
    x         Exit program
    w         Open the welcome sequence
    
    s         Open the store to buy assets
    1         Buy asset with Call code '1'
    2         Buy asset with Call code '2'
    ..

    c         Open this commands board
    0         Collect income
    
    e         Special events(coming soon:)
    t         Access lower tier
    T         Access upper tier
*/

/*
    Things to improve:-
    1.Make the store appear on-command
    2.Expand the types of assets
    3.Add a 'month counter' (counting number of moves made)
    
    4.Write comments
    5.Check for cases where player types a wrong move
    
    *6.Divide properties into tiers, where items of one tier 
    are much more costly and income-earning than the previous;
    make the display such that it shows items of one tier alone;
    make the Assets owned display show only those tiers which 
    player owns something
    
    7.Add option to take on debt; if player goes bankrupt, starts with
    starting money and half his assets
    8.~~Add variables for monthly income, net wealth
    9.~~Improve UBI (Universal Basic Income) concept
    
    10.Put up a commands board:-
        i)'d' for display
        ii)'x' for exit
        iii)'c' for opening the commands board(mention this in start screen)
        iv)'0' for next move
        v)'e' for special events(to be developed)
        vi)'t' for the tier below
        vii)'T' for tier above
    
    11.Make commands order-invariant by using 'inp || inp_alt' style functs
    12.~~Improve monthly income display
    13.Add inflation (x1.75 every 10 yrs)
*/

/*
    Tier checkpoints (based on capital)
    1 - $0
    2 - $2,000,000
*/

//  IMPLEMENT TIER SYSTEM BY CONVERTING assets_count, costs, income 
//  ARRAYS INTO 2D ARRAYS OF FORM FUNCT[TIER][S.NO]

//Find a way to transition tiers

#include <iostream>
using namespace std;

//Show the store
void show_store(int tier) {
    if (tier < 1) {
        cout << "\nThings you can buy:-\n";
        cout << "(Tier 1)\n";
        cout << "Name                   Cost       Call code  Production per turn\n";
        cout << "Lemonade stand         $1000      1          $50\n";
        cout << "V.Small bakery         $2500      2          $100\n";
        cout << "Small Tatoo shop       $4500      3          $250\n";
        cout << "V.Small Hardware store $7950      4          $390\n";
        cout << "V.Small Restaurant     $20,000    5          $900\n";
        cout << "V.Small Manga Store    $42,000    6          $2250\n";
    }
    //if (tier < 2) {
        cout << "\n(Tier 2)\n";
        cout << "Name                 Cost         Call code  Production per turn\n";
        cout << "Small bakery         $200,000     1          $12,000\n";
        cout << "V.Small software co. $450,000     2          $25,000\n";
        cout << "Tatoo shop           $800,000     3          $36,500\n";
    //}
}

//Show the welcome sequence
void show_intro() {
    cout << "\nWelcome to The Idle Clicker!(Version 1.0)\n";
    cout << "Press 0 and ENTER to collect your income!\n";
    cout << "Press 1-9 and ENTER to buy assets!\n";
    cout << "\nFor now, press ENTER to continue: ";
    getwchar();

    cout << "\nPress 'w' to open this welcome sequence!\n";
    cout << "Press 'c' to open commands\n";
    cout << "Press 'h' for help, if you don't understand something\n";
    cout << "[ENTER]";
    getwchar();

    cout << "\nPress 's' to view store\n";
    cout << "Press 'x' to exit\n";
    cout << "[ENTER]";
    getwchar();

    cout << "\nAnyway, let's get started!\n";
    cout << "Press 0 and ENTER until you hit 1000, then hit 1 and ENTER\n";
    cout << "To buy a Lemonade stand!\n";
    cout << "[ENTER]";
    getwchar();
}

//Show list of commands available
void commands() {
    cout << "COMMANDS BOARD\n\n";
    
    cout << "Commands you can use:-\n";
    cout << "Command   Use\n";
    cout << "h         Open help\n";
    cout << "x         Exit program\n";
    cout << "w         Open the welcome sequence\n\n";
    
    cout << "s         Open the store to buy assets\n";
    cout << "1         Buy asset with Call code '1'\n";
    cout << "2         Buy asset with Call code '2'\n";
    cout << "..\n\n";
    
    cout << "c         Open this commands board\n";
    cout << "0         Collect income\n\n";
    
    cout << "e         Special events(coming soon:)\n";
    cout << "t         Access lower tier\n";
    cout << "T         Access upper tier\n\n";  
}

//Show how to play the game, in a more detailed manner
void help() {}

int inputs(char inp, char inp_alt, char i) {
    if (inp == i || inp_alt == i) {
        return 0;
    } else {
        return 1;
    }
}

//void show_assets();

int main() {
    //Intro
    show_intro();

    //Input variable delarations
    char inp;
    char inp_alt;

    //Monetary variable declarations (var[tier no. -1][item no.])
    int assets_count[3][10];
    long int costs[3][10];
    long int income[10];
    unsigned long long int capital = 850;
    int tier = 0;

    //Costs of business operations
    costs[0][0] = 1000;
    costs[0][1] = 2500;
    costs[0][2] = 4500;
    costs[0][3] = 7950;
    costs[0][4] = 20000;
    costs[0][5] = 42000;

    //Income paid out by each type of business /mo
    income[0] = 50;
    income[1] = 100;
    income[2] = 250;
    income[3] = 390;
    income[4] = 900;
    income[5] = 2250;

    //Income and wealth variable declarations
    unsigned long long int wealth;
    int UBI = 50;
    unsigned long long int net_income = UBI;

    //Months passed
    int months;
    
    show_store(0);
    
    //Loop to start game
    while (true) {
        //Show assets owned
        cout << "\nThings you own:-\n";
        cout << "Name                   Quantity  Income\n";
        cout << "Lemonade stand         " << assets_count[0][0] << "        $" << assets_count[0][0] * income[0] << "\n";
        cout << "V. Small bakery        " << assets_count[0][1] << "        $" << assets_count[0][1] * income[1] << "\n";
        cout << "Small Tatoo shop       " << assets_count[0][2] << "        $" << assets_count[0][2] * income[2] << "\n";
        cout << "V.Small Hardware store " << assets_count[0][3] << "        $" << assets_count[0][3] * income[3] << "\n";
        cout << "V.Small Restaurant     " << assets_count[0][4] << "        $" << assets_count[0][4] * income[4] << "\n";
        cout << "V.Small Manga Store    " << assets_count[0][5] << "        $" << assets_count[0][5] * income[5] << "\n";

        //Tier 2 assets
        if (tier > 1) {
            cout << "\n(Tier 2)\n";
            cout << "Name                 Quantity  Income\n";
            cout << "Small Bakery         " << assets_count[1][0] << "        $" << assets_count[1][0] * income[0] << "\n";
        }


        //Tell the player's current status(capital available, monthly income, debt, etc.)
        cout << "\nYear " << months / 12 + 1 << " month " << months % 12 + 1;
        cout << "\nYour on-hand capital:- " << capital;
        cout << "\nYour monthly income:- " << net_income;

        //Take the player's input move
        cout << "\n\nTier " << tier + 1;
        cout << "\nYour Move >>>";
        inp = getwchar();
        inp_alt = getwchar(); //Redundancy for 'x', if it falls on 2nd step

        //To exit game
        if (inp == 'x' || inp == 'X' || inp_alt == 'x' || inp_alt == 'X') {
            break;
        }

        //Showable stuff
        if (inputs(inp, inp_alt, 's') == 0) {
            cout << "\nSTORE\n";
            show_store(0);
        }
        if (inputs(inp, inp_alt, 'w') == 0) {
            show_intro();
        }
        if (inputs(inp, inp_alt, 'c') == 0) {
            commands();
        }
        if (inputs(inp, inp_alt, 'h') == 0) {
            help();
        }
        
        //To buy a mode of production
        for (int i = 0; i < 10; i++) { 
            if ( ((int) inp == 49 + i && capital >= costs[tier][i]) || ((int) inp_alt == 49 + i && capital >= costs[tier][i]) ) {
                assets_count[tier][i]++;
                capital -= costs[tier][i];
            } else if ( ((int) inp == 49 + i && capital < costs[tier][i]) || ((int) inp_alt == 49 + i && capital < costs[tier][i]) ) {
                cout << "Insufficient capital!\n";
            }
        }

        //Defines net income for next week
        net_income = UBI;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 3; j++) {
                net_income += assets_count[j][i] * income[i];
            }
        }

        //Default increase due to Universal Basic Income
        if (net_income > 400) {
            net_income -= UBI;
        }

        //Add net income to capital
        if (inputs(inp, inp_alt, '0') == 0) {
            capital += net_income;
        } else {
            //Even if cmd was not used, half income gets added            
            capital += net_income / 2;
        }
        //Increase number of months passed by 1
        months++;
    }

    //Wealth includes capital on-hand
    wealth = capital;
    //Wealth also includes assets owned, at 80% of their cost when bought
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            wealth += (costs[j][i] * assets_count[j][i] * 4) / 5;
        }
    }
    cout << "\nYour wealth is $" << wealth << "\n";

    return 0;
}

//Find way to globally declare variables
/*void show_assets() {
    cout << "\nThings you own:-\n";
    cout << "Name                   Quantity  Income\n";
    cout << "Lemonade stand         " << assets_count[0] << "        $" << assets_count[0] * income[0] << "\n";
    cout << "Small bakery           " << assets_count[1] << "        $" << assets_count[1] * income[1] << "\n";
    cout << "Tatoo shop             " << assets_count[2] << "        $" << assets_count[2] * income[2] << "\n";
    cout << "Small Hardware store   " << assets_count[3] << "        $" << assets_count[3] * income[3] << "\n";
    cout << "small Restaurant       " << assets_count[4] << "        $" << assets_count[4] * income[4] << "\n";
    cout << "Very Small Manga Store " << assets_count[5] << "        $" << assets_count[5] * income[5] << "\n";
}*/ 