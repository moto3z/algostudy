#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
//#include <cstring>
//#include <cstdio>
//#include <cstdlib>

using namespace std;

struct _best {
    string gnr;
    int idx;

}typedef mysongs;

//map<_best> mymap;
vector<int> solution(vector<string> genres, vector<int> plays) {

    vector<int> answer;
    map<string, int> music;
    //장르별 재생횟수 파악하는 용(장르의 순서 결정)

    map<string, map<int, int>> mslst;
    //각 장르별 곡들이 몇번이나 재생되는지(장르내 1등,2등 뽑기)



    int len = genres.size();
    for (int i = 0; i < len; i++) {
        music[genres[i]] += plays[i];
        mslst[genres[i]][i] = plays[i];
        //그리고 musiclist map에 장르로 key로 접근해서
        //재생횟수와 index를 추가합니다.
    }
    



    while (music.size() > 0) {
        string genre;
        int maxi = 0;
        for (auto i : music) {
            if (maxi < i.second) {
                maxi = i.second;
                genre = i.first;

            }
        }
        //music 이라는 map을 이용해 장르는 key값
        // 각각의 장르가 총 재생된 횟수를 구하는 부분


        

        for (int i = 0; i < 2; i++) {
            //장르별로 2곡씩 수록해야 하므로, 
            int val = 0, ind = -1;
            for (auto ml : mslst[genre]) {
                if (val < ml.second) {
                    val = ml.second;
                    ind = ml.first;
                }
            }
            if (ind == -1) {
                break;
                //장르에 곡이 없거나 한곡뿐이라면, 반복문 탈출
            }
            else {}
           
            answer.push_back(ind);
            mslst[genre].erase(ind);
        }
        music.erase(genre);
        // 곡 수록이 끝난 장르는 삭제하고 다음 장르!




    }
    



    


    return answer;
}

int main() {
    vector<string> gnres = { "classic","pop","classic","classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };
    vector<int> ans = { 4, 1, 3, 0 };

    vector<int>ret = solution(gnres, plays);
    if (ret == ans) {
        cout << "OK!" << endl;
    }
    else {
        cout << "NO : " << endl;
        for (auto i : ret) {
            cout << i << endl;
        }

    }

    return 0;

}

