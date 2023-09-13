#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

//#include <cstring>
//#include <cstdio>
//#include <cstdlib>

using namespace std;

const int DEBUG = 0;

bool lcomp(string a, string b) {
    int la = a.length();
    int lb = b.length();
    if (la < lb) {
        return true;
    }
    else if (la > lb) {
        return false;
    }
    else if (la == lb) {
        return (a < b);
    }
    else {
        //이런경우는 없다
        return (a < b);
    }
    
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end(), lcomp);
    int n = phone_book.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int ret = phone_book[j].find(phone_book[i]);
            //if (0<= ret && ret<=n) {
            if (0== ret) {
                return false;
            }
        }
    }



    return answer;
}

int main() {
    vector<string> tc1 = { "119", "97674223", "1195524421" };
    vector<string> tc2 = { "456", "789","123" };
    vector<string> tc3 = { "12", "123", "1235", "567", "88" };
    vector<string> tc4 = { "12345", "12345", "12345", "12345" };
    vector<string> tc5 = { "1", "21", "321", "45123" ,"5"};
    bool ret1 = solution(tc1);
    bool ret2 = solution(tc2);
    bool ret3 = solution(tc3);
    
    if ((ret1 == false) && (ret2 == true) && (ret3 == false)) {
        cout << "OK!!!" << endl;
    }
    else {
        cout << "NO T.T" << endl;
        cout << ret1 << ' ' << ret2 << ' ' << ret3;
    }


    bool ret4 = solution(tc5);

    cout << "+tc:"<<ret4 << endl;



    return 0;
}
