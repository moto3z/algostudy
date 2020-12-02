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
vector<int> initr;
struct _best {
    string name;
    int np;
    vector<int>songs = initr;
    
}typedef best;

int finder(vector<string> ori, string target);
bool comp(best a, best b);

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    vector<int> answer;
    vector<string> gnr;//중복제거 장르
    vector<int> gnum;//장르별 플레이 횟수
    int len = genres.size();
    int map[101] = { 0, };

    
    //장르구하기
    for (int i = 0; i < len; i++) {
        int is_alreadyEx = finder(gnr, genres[i]);
        if (is_alreadyEx >= 0) {
            gnum[is_alreadyEx] += plays[i];

        }
        else {
            gnum.push_back(plays[i]);
            gnr.push_back(genres[i]);
        }
    }
    
    
    //
    
    vector<best> album_genr_ord;
    len = gnr.size();
    for (int i = 0; i < len; i++) {
        best temp;
        temp.name = gnr[i];
        temp.np = gnum[i];
        temp.songs = initr;
        album_genr_ord.push_back(temp);
    }

    sort(album_genr_ord.begin(), album_genr_ord.end(),comp);
    

    //장르별 2곡씩 추가
    len = album_genr_ord.size();
    for (int i = 0; i < len; i++) {
        //
    }




    return answer;
}

int main() {
    vector<string> genres = { "classic","pop","classic","classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };
    vector<int> ans = { 4, 1, 3, 0 };

    vector<int>ret = solution(genres, plays);
    if (ret == ans) {
        cout << "OK!" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;

}


int finder(vector<string> ori, string target) {
    int iori = ori.size();

    for (int i = 0; i < iori; i++) {
        if (ori[i] == target) {
            return i;
            //find!!
        }
    }

    return (-1);
}



bool comp(best a, best b) {
    return (a.np > b.np);
}
