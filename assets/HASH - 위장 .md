# HASH - 위장

생성일: 2020년 12월 1일 오후 12:54

# 문제

- 문제링크 [https://programmers.co.kr/learn/courses/30/lessons/42578](https://programmers.co.kr/learn/courses/30/lessons/42578)
- 스파이가 가진 의상들이 담긴 2차원 배열 clothes가 주어질 때
- 서로 다른 옷의 조합의 수를 return 하도록 solution 함수를 작성

# 풀이

- 두가지 구현 방법
    1. map 자료구조  :  Key:Value 로 clothes배열에다 집어넣고 KEY별 경우의 수 -1(아무것도 안입는경우)
    2. 구현  :  어쨋거나 [의상의 종류]와 [의상종류별 가짓수] 두개만 알면 경우의수 따져셔 풀수 있으니까  일일이 중복검사하고, 가짓수를 세서 해결

# 코드

```cpp
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

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

/*

입출력 예
clothes return

{{"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"}} 
5

{{"crow_mask", "face"},{"blue_sunglasses", "face"},{"smoky_makeup", "face"}} 
3

*/
```

# 해설

```cpp
//int solution(vector<vector<string>> clothes) {
//int answer=1;
//int jongryu[31] = { 0, };
//vector<string> kind;
//int len = clothes.size();

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
```

- kind : 착용할 부위별로 몇개씩 등장하는지 Count하기 위한 백터

```cpp
int str_search(vector<string> ori, string key) {
    int li = ori.size();

    for (int i = 0; i < li; i++) {
        if (ori[i] == key) {
            return i+10;
        }
    }
    return 0;

}

```

- 0을 리턴 : 찾을수 없으므로 새로운 옷의 종류
- 0이 아닌 다른값이 리턴되면 : 해당 위치의 인덱스에 존재함!
- +10해준 이유 : 0 번 인덱스에 위치한다면