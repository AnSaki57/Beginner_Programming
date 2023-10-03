/*
    take M1 of side axb, M2 cxa
    M3 cxb
    for evry c
        for evry b
            for evry a
                ij += kj*ik
            //ij += 0j*i0 + 1j*i0+...
*/

/*
    1 2     2 5 8 3
    2 5     1 9 9 3
    4 1
*/

/*
    for (int i = 0; i < INSERT; i++) {
        for (int j = 0; j < INSERT; j++) {
            
        }
    }
*/

#include <iostream>

int main() {
    const int a = 4;
    const int b = 4;
    const int c = 4;

    //initialise matrices
    int M1[c][a];
    int M2[a][b];
    int M3[c][b];

    //set all values to 0
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < a; j++) {
            M1[i][j] = 0;
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            M2[i][j] = 0;
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < b; j++) {
            M3[i][j] = 0;
        }
    }

    //take vals of M1
    while (true) {
        std::cout << "\n(for Matrix 1)\n";
        int x_val;
        int y_val;
        char value;

        std::cout << "x: ";
        std::cin >> x_val;
        if (x_val == -1) {
            break;
        }
        if (!(x_val > 0 && x_val <= c)) {
            std::cout << "Err\n";
            continue;
        }

        std::cout << "y: ";
        std::cin >> y_val;
        if (y_val == -1) {
            break;
        }
        if (!(y_val > 0 && y_val <= a)) {
            std::cout << "Err\n";
            continue;
        }

        std::cout << "val: ";
        std::cin >> value;
        if (value == -1) {
            break;
        } else {
            M1[x_val-1][y_val-1] = ((int) value) - 48;
        } 
    }
    std::cout << std::endl;

    //print M1
    for (int i = 0; i < c; i++) {
        std::cout << "[ ";
        for (int j = 0; j < a; j++) {
            std::cout << M1[i][j] << " ";
        }
        std::cout << "]\n";
    }
    
    //take vals of M2
    while (true) {
        std::cout << "\n(for Matrix 2)\n";
        int x_val;
        int y_val;
        char value;

        std::cout << "x: ";
        std::cin >> x_val;
        if (x_val == -1) {
            break;
        }
        if (!(x_val > 0 && x_val <= c)) {
            std::cout << "Err\n";
            continue;
        }

        std::cout << "y: ";
        std::cin >> y_val;
        if (y_val == -1) {
            break;
        }
        if (!(y_val > 0 && y_val <= a)) {
            std::cout << "Err\n";
            continue;
        }

        std::cout << "val: ";
        std::cin >> value;
        if (value == -1) {
            break;
        } else {
            M2[x_val-1][y_val-1] =  ((int) value) - 48;
        }
    }
    std::cout << std::endl;

    //print M2
    for (int i = 0; i < a; i++) {
        std::cout << "[ ";
        for (int j = 0; j < b; j++) {
            std::cout << M2[i][j] << " ";
        }
        std::cout << "]\n";
    }

    //core matrix multiplication
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < a; k++) {
                M3[i][j] += M2[k][j] * M1[i][k];
            }
        }
    }

    std::cout << std::endl;
    std::cout << "(press 0 and Enter to continue): ";
    int input;
    std::cin >> input;
    std:: cout << std::endl;
    //print M3
    for (int i = 0; i < c; i++) {
        std::cout << "[ ";
        for (int j = 0; j < b; j++) {
            std::cout << M3[i][j] << " ";
        }
        std::cout << "]\n";
    }
}