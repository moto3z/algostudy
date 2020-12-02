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


int str_search(vector<string> ori, string key) {
    int li = ori.size();

    for (int i = 0; i < li; i++) {
        if (ori[i] == key) {
            return i+10;
        }
    }
    return 0;

}

int solution(vector<vector<string>> clothes) {
    int answer=1;
    int jongryu[31] = { 0, };
    //0은 안씀, 1부터 존재함

    vector<string> kind;
    //clothes[i][0] : 아이템명
    //clothes[i][1] : 아이템의 종류
    int len = clothes.size();
    for (int i = 0; i < len; i++) {
        int is_in = str_search(kind, clothes[i][1]);
        if (is_in) {
            //is_in-10 위치에 존재함
            jongryu[is_in - 10+1]++;
        }
        else {
            
            kind.push_back(clothes[i][1]);
            jongryu[kind.size()]++;
        }
    }
    

    len = kind.size();
    for (int i = 1; i <= len; i++) {
        answer = answer * (jongryu[i] + 1);
    }
    
    return (answer-1);
}

int main() {
    int ret;
    vector<vector<string>> tc1 = { {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };
    int a1 = 5;
    vector<vector<string>> tc2 = { {"crow_mask", "face"},{"blue_sunglasses", "face"},{"smoky_makeup", "face"} };
    int a2 = 3;
    
    ret = solution(tc1);
    if (ret == a1) {
        cout << "OK!!" << endl;
    }
    else {
        cout << "No : " << ret << endl;
    }

    ret = solution(tc2);
    if (ret == a2) {
        cout << "OK!!" << endl;
    }
    else {
        cout << "No : " << ret << endl;
    }




    return 0;
}
/*

입출력 예
clothes return


{{"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"}} 
5


{{"crow_mask", "face"},{"blue_sunglasses", "face"},{"smoky_makeup", "face"}} 
3

*/