/*
    Design a code that takes an X*X relation and adds aRb pairs such that 
    R becomes an equivalent relation
*/

/*
    Equivalence:-
        1)Reflexive - aRa V a (= D
        2)Symmetric - aRb -> bRa V a,b (= D
        3)Transitive - aRb A bRc -> aRc V a,b,c (= D
*/

/*
    Board:-

      1 2 3 4 ..
    1 X X   X ..
    2   X   X ..
    3 X   X   ..
    4   X   X ..
    : : : : :
*/

/*
    assign side length to a const Side
    Make an SxS array
    Prompt user for aRb pairs
    Display board as per user's inputs
        If aRb, then put 'X', else ' '
    Do all reflexive rels
    Do all symmetric rels
*/

/*
    Compound for loop

    for (int i = 0; i < Side; i++) {
        for (int j = 0; j < Side; j++) {

        }
    }
*/

#include <iostream>

//learn arrays and pointers to do this, doesn't work this way
//void printBoard(bool Board[int Side][int Side]) {}        prints board
//bool Equivalentise(bool Board[int Side][int Side]) {}     does reflection, symmetry, and transitivity

int main() {
    char inp;
    std::cout << "Welcome to Equivalence relation converter!\n";
    std::cout << "Enter pairs of 'a' and 'b' such that (a,b) satisfy a\n";
    std::cout << "desired relation R (aRb)\n"; 
    std::cout << "\n(Press 0 and ENTER to continue): ";
    std::cin >> inp;

    std::cout << "\n'a' and 'b' lie between 1 to 9,\n";
    std::cout << "so please keep inputs between those numbers.\n";
    std::cout << "\n(Press 0 and ENTER to continue): ";
    std::cin >> inp;

    std::cout << "\nPlease enter your relations:\n";

    //initialise side length and declare relational graph
    const int Side = 9;
    bool isPartOfR[Side][Side];

    //set all pairs of aRb to false, initially
    for (int i = 0; i < Side; i++) {
        for (int j = 0; j < Side; j++) {
            isPartOfR[i][j] = false;
        }
    }

    //initialise inputs
    int exit_val = -1;
    std::cout << "(Input '" << exit_val << "' to exit)\n";
    int x_val = 0;
    int y_val = 0;
    
    //loop until user is done giving relations
    while (x_val != exit_val || y_val != exit_val) {
        std::cout << "Enter 'a': ";
        std::cin >> x_val;
        
        std::cout << "Enter 'b': ";
        std::cin >> y_val;
        
        std::cout << std::endl;

        if (x_val == exit_val || y_val == exit_val) {
            break;
        }
        if (x_val < 1 || x_val > Side || y_val < 1 || y_val > Side) {
            std::cout << "Invalid input. Please try again.\n\n";
            continue;
        }

        isPartOfR[x_val - 1][y_val - 1] = true;
    }

    //print board
    std::cout << "\n  ";
    for (int i = 0; i < Side; i++) {
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < Side; i++) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < Side; j++) {
            if (isPartOfR[i][j]) {
                std::cout << "X";
            } else {
                std::cout << " ";
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n(Press 0 and ENTER to output equivalence relation): ";
    std::cin >> inp;

    //make reflexive
    for (int i = 0; i < Side; i++) {
        isPartOfR[i][i] = true;
    }

    //make symmetric and transitive, loop as long as there r elements meant to be
    //changed; loop until a loop yields no changes
    for (bool changes = true; changes;) {
        changes = false;
        
        //make symmetric
        for (int i = 0; i < Side; i++) {
            for (int j = 0; j < Side; j++) {
                if (isPartOfR[i][j] && !isPartOfR[j][i]) {
                    isPartOfR[j][i] = true;
                    changes = true;
                }
            }
        }

        //make transitive (***)
        for (int i = 0; i < Side; i++) {
            for (int j = 0; j < Side; j++) {
                for (int k = 0; k < Side; k++) {
                    if (isPartOfR[i][j] && isPartOfR[j][k] && !isPartOfR[i][k]) {
                        isPartOfR[i][k] = true;
                        changes = true;
                    }
                }
            }
        }
    }

    //print board
    std::cout << "\n  ";
    for (int i = 0; i < Side; i++) {
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < Side; i++) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < Side; j++) {
            if (isPartOfR[i][j]) {
                std::cout << "X";
            } else {
                std::cout << " ";
            }
            //std::cout << i << j;
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}