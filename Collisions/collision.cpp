/*
    Demonstrate how the 2 bodies r colliding
    Ask user for coefficientt of restitution, vel 1, vel 2 (u1, u2), mass 1, mass 2
    calc v1, v2
*/

/*
    v1 = ((m1-m2)/(m1+m2)) * u1 + (2 * m2 / (m1+m2)) * u2
/

/*
    O -> u1                        u2 <- O
                v1 <- O O -> v2
*/

#include <iostream>

int main() {
    char input;
    
    std::cout << "Welcome to Collision calculator!\n";
    std::cout << "Calculate the final velocities of any 1-D collision between 2 bodies!\n";
    std::cout << "(Press 0 and enter to continue): ";
    std::cin >> input;

    std::cout << "\n\n----------------------------------------\n";
    std::cout << "M1 ->u1                          u2<- M2\n";
    std::cout << "----------------------------------------\n";
    std::cout << "----------------------------------------\n";
    std::cout << "             v1<- M1 M2 ->v2\n";
    std::cout << "----------------------------------------\n\n";
    std::cout << "The directions of initial and final velocities are as given above,\n";
    std::cout << "negative values give reverse directions\n";
    std::cout << "(Press 0 and enter to continue): ";
    std::cin >> input;

    double e;
    double m1;
    double m2;
    double u1;
    double u2;
    double v1;
    double v2;

    std::cout << "\nCoefficient of restitution: ";
    std::cin >> e;
    
    std::cout << "Mass of first body: ";
    std::cin >> m1;
    std::cout << "Mass of second body: ";
    std::cin >> m2;
    
    std::cout << "\n(Initial) Velocity of first body:";
    std::cin >> u1;
    std::cout << "(Initial) Velocity of second body:";
    std::cin >> u2;


    v1 = ((1+e) * m2 / (m1+m2)) * u2 - ((m1-(e*m2))/(m1+m2)) * u1;
    v2 = ((1+e) * m1 / (m1+m2)) * u1 - ((m2-(e*m1))/(m1+m2)) * u2;

    std::cout << "\nFinal veocity of first body: " << v1 << std::endl;
    std::cout << "Final veocity of second body: " << v2 << std::endl;
}