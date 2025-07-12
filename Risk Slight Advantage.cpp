#include <iostream>
using namespace std;

int main() {
    int threeD6[21][3] = {};//each subset is the combination of the two numbers attained from rolling 2d6 and dropping the lowest, and the third number is the probability out of a total of 216 of getting those numbers.
    int crunch[21] = {16, 27, 21, 15, 9, 3, 13, 21, 15, 9, 3, 10, 15, 9, 3, 7, 9, 3, 4, 3, 1};//the probabilities for each ordered set in threeD6 i crunched by hand.
    int twoD6[21][3] = {};//same as threeD6, but with 2d6 and no dropping.
    int temp = 0;//iteration value for setup
    for (int i = 6; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            threeD6[temp][0] = i;
            twoD6[temp][0] = i;
            threeD6[temp][1] = j;
            twoD6[temp][1] = j;
            threeD6[temp][2] = crunch[temp];
            if (i == j) {//the values for twoD6 in the third space are much simpler
                twoD6[temp][2] = 6;
            } else {
                twoD6[temp][2] = 12;
            }
            temp++;
        }
    }
    /*for (int i = 0; i < 21; i++) {//used for debugging purposes to see the lists threeD6 and twoD6 after setup.
        for (int j = 0; j < 3; j++) {
            cout << twoD6[i][j] << ", ";
        }
        cout << endl;
    }*/
    int dWins = 0;// how many times the attacker lost 2 units
    int ties = 0;// how many times both players lost a unit
    int aWins = 0;// how many times the defender lost 2 units

    return 0;
}
