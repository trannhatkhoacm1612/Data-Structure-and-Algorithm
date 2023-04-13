#include<iostream>

using namespace std;

bool findSeat(int numStudent, int numTest, int row, int seat){
    if (numStudent == 2) return false;
    if (numTest % 2){
         if (seat == 1){
            if (row + numTest/2 <= (numStudent + 1)/2){
                if ((row + numTest/2) * 2 > numStudent) return false;
                cout << row + numTest/2 << ' ' << 2;
                return true;
            } else if (row - numTest/2 - 1 > 0){
                cout << row - numTest/2 - 1 << ' ' << 2;
                return true;
            } else return false;
        } else {
            if (row - numTest/2 > 0){
                cout << row - numTest/2 << ' ' << 1;
                return true;
            } else if (row + numTest/2 + 1 <= (numStudent + 1)/2){
                cout << row + numTest/2 + 1 << ' ' << 1;
                return true;
            } else return false;
        }
    } else {
        if (row - numTest/2 > 0){
            cout << row - numTest/2 << ' ' << seat;
            return true;
        } else if (row + numTest/2 <= (numStudent + 1)/2){
            if (seat == 2 && (row + numTest/2) * 2 > numStudent) return false;
            cout << row + numTest/2 << ' ' << seat;
            return true;
        } else return false;
    }
}

int main(){
    int numStudent, numTest, aliceRow, aliceSeat;
    cin >> numStudent >> numTest >> aliceRow >> aliceSeat;
    if (!findSeat(numStudent, numTest, aliceRow, aliceSeat)) cout << -1;
    return 0;
}