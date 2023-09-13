# HASH - 베스트엘범

생성일: 2020년 12월 2일 오후 9:36

# 문제

- 문제링크

# 풀이

# 코드

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct _s {
    string key;
    int val;
}smp;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> gnr_playtimes;
    map<string, map<int, int>> bestof_in_gnr;
    

    //장르별로 플레이횟수를 구하기
    int len = genres.size();
    for (int i = 0; i < len; i++) {
        gnr_playtimes[genres[i]] += plays[i];
        //genres[i] string값을 Key로 plays 를 하나씩 추가

        bestof_in_gnr[genres[i]][i] = plays[i];
        //##
        // 이중 map
        //1차 Key: 장르명 중에서 >>> 2차 Key : plays의 인덱스
    }
    

    
    for (int i = 0; i < genres.size(); i++) {
        string bestgnr;
        int maxi = 0;

        for (auto i : gnr_playtimes) {
            if (maxi < i.second) {
                //value 값 기준 가장 큰걸로
                maxi = i.second; // 재생횟수 기준
                bestgnr = i.first; // 장르의 이름
            }
        }

        for (int i = 0; i < 2; i++) {
            //장르별로 많이 재생된 2곡씩 수록해야 함
            int max_play_song = 0;
            int mps_idx = -1;
            for (auto j : bestof_in_gnr[bestgnr]) {
                //가장 많이 재생된 장르(bestgnr) 중에서

                //가장 많이 재생된 곡을 구하기 위해
                
                if (max_play_song < j.second) {
                    max_play_song = j.second;
                    mps_idx = j.first;//위에서의 2차키가 인덱스
                }
            }

            if (mps_idx == -1) {
                //인덱스가 기본값인경우, 못찾음, 원소가 없거나 한곡뿐인 상황
                break;
            }
            else {

            }
            

            answer.push_back(mps_idx);
            bestof_in_gnr[bestgnr].erase(mps_idx);
            // 정답백터에 추가하고
            //추가한게 또 들어가지 않게 map에서 삭제해줌

        }

        gnr_playtimes.erase(bestgnr);
    
    }

    return answer;
}

```

# 해설

```cpp
    map<string, int> gnr_playtimes;
    map<string, map<int, int>> bestof_in_gnr
```

- 설명

```cpp
 

    //장르별로 플레이횟수를 구하기
    int len = genres.size();
    for (int i = 0; i < len; i++) {
        gnr_playtimes[genres[i]] += plays[i];
        //genres[i] string값을 Key로 plays 를 하나씩 추가

        bestof_in_gnr[genres[i]][i] = plays[i];
        //##
        // 이중 map
        //1차 Key: 장르명 중에서 >>> 2차 Key : plays의 인덱스
    }
   
```

- 설명

```cpp
 

    
    for (int i = 0; i < genres.size(); i++) {
        string bestgnr;
        int maxi = 0;

        for (auto i : gnr_playtimes) {
            if (maxi < i.second) {
                //value 값 기준 가장 큰걸로
                maxi = i.second; // 재생횟수 기준
                bestgnr = i.first; // 장르의 이름
            }
        }

        for (int i = 0; i < 2; i++) {
            //장르별로 많이 재생된 2곡씩 수록해야 함
            int max_play_song = 0;
            int mps_idx = -1;
            for (auto j : bestof_in_gnr[bestgnr]) {
                //가장 많이 재생된 장르(bestgnr) 중에서

                //가장 많이 재생된 곡을 구하기 위해
                
                if (max_play_song < j.second) {
                    max_play_song = j.second;
                    mps_idx = j.first;//위에서의 2차키가 인덱스
                }
            }

            if (mps_idx == -1) {
                //인덱스가 기본값인경우, 못찾음, 원소가 없거나 한곡뿐인 상황
                break;
            }
            else {

            }
            

            answer.push_back(mps_idx);
            bestof_in_gnr[bestgnr].erase(mps_idx);
            // 정답백터에 추가하고
            //추가한게 또 들어가지 않게 map에서 삭제해줌

        }
```

- 장르별 두곡씩 추가해주는 부분