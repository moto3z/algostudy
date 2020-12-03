#include <iostream>

using namespace std;

int main() { 


    int map[4][4] = {
        1,2,3,4,
        4,5,6,7,
        1,2,3,4,
        6,7,8,-1
    };


    for(int yi=0 ; yi<4 ; yi++ ) {
        for(int xj=0 ; xj<4 ; xj++) {
            cout << map[yi][xj] << ' ';
        }
        cout << endl;
    }


    if(map[3][3] == -1 ) {
        cout << "???" << endl;
    }

    return 0;
}