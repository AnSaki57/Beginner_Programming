/*
    Code for checking, if 2 rectangles are actually
    parts of a square. A square was said to be cut 
    parallel to one of its sides, and we havto check
    if the dimensions of the two rectangles given
    can be proof whether the above description matches
    the rectangles or not.

    Take dimensions of each of the two rectangles,
    and store them based on how large they are,
    in 2 different arrays(one for the larger sides,
    one for the smaller sides).
    
    Compare if
    1)Larger sides r both equal
    2)Smaller sides' sum equals one of the larger
    sides
*/

#include <stdio.h>

int main() {
    //Number of pairs of rectangles to check
    int t;
    scanf("%d", &t);
    
    for (int i; i < t; i++) {
        //Dimensions of first(a,b), and second(c,d)
        //rectagles
        int a, b, c, d;
        scanf("%d %d", &a, &b);
        scanf("%d %d", &c, &d);
    
        int large[2];   //Array for the larger sides
        int small[2];   //Array for the smaller sides
    
        //Sorting a & b into the arrays
        if (a > b)  {
            large[0] = a;
            small[0] = b;
        } else if (a < b) {
            large[0] = b;
            small[0] = a;
        } else {
            printf("No\n"); //Both cant be same length
            continue;
        }

        //Sorting c & d into arrays
        if (c > d)  {
            large[1] = c;
            small[1] = d;
        } else if (c < d) {
            large[1] = d;
            small[1] = c;
        } else {
            printf("No\n");
            continue;
        }
        
        //If larges r not same, then condition fails
        if (large[0] != large[1]) {
            printf("No\n");
            continue;
        }
        
        //If smalls r not equal to one of the
        //larges, condition fails
        if (small[0] + small[1] != large[0]) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
}