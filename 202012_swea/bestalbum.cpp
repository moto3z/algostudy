
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

struct __best {
    int ptimes;
    int idx;

}typedef mysongs;

struct _best {
    string name;
    int np;
    vector<mysongs> songs;

}typedef best;


int finder(vector<string> ori, string target);
bool comp(best a, best b);
bool songcomp(mysongs a, mysongs b);
vector<mysongs> getsongs(vector<string> ori, vector<int> nums, string target);
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
    
    
    //장르의 순서를 결정합니다
    vector<best> album_genr_ord;
    len = gnr.size();
    for (int i = 0; i < len; i++) {
        best temp;
        temp.name = gnr[i];
        temp.np = gnum[i];
        vector<mysongs> gnr_song = getsongs(genres,plays,gnr[i]);
        //장르별로 재생횟수를 구해옵니다.
        temp.songs = gnr_song;
        album_genr_ord.push_back(temp);
    }
    sort(album_genr_ord.begin(), album_genr_ord.end(),comp);
    

    //장르별 2곡씩 추가
    len = album_genr_ord.size();
    for (auto i : album_genr_ord) {
        sort(i.songs.begin(), i.songs.end(),songcomp);
        answer.push_back(i.songs[0].idx);
        if (album_genr_ord.size() >= 2) {
            answer.push_back(i.songs[1].idx);
        }
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
        cout << "NO : " <<endl;
        for (auto i : ret) {
            cout << i << endl;
        }
        
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

bool songcomp(mysongs a, mysongs b) {
    return (a.ptimes > b.ptimes);
}



vector<mysongs> getsongs(vector<string> ori, vector<int> nums, string target) {
    string s = ori[1];
    int len = ori.size();
    mysongs tmp;

    vector<mysongs> gsongs;


    for (int i = 0; i < len; i++) {
        if (ori[i] == target) {
            tmp.ptimes = nums[i];
            tmp.idx = i;
            gsongs.push_back(tmp);
        }
    }


    return gsongs;
}


/*

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

struct __best {
    int ptimes;
    int idx;

}typedef mysongs;

struct _best {
    string name;
    int np;
    vector<mysongs> songs;

}typedef best;


int finder(vector<string> ori, string target);
bool comp(best a, best b);
bool songcomp(mysongs a, mysongs b);
vector<mysongs> getsongs(vector<string> ori, vector<int> nums, string target);
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
    
    
    //장르의 순서를 결정합니다
    vector<best> album_genr_ord;
    len = gnr.size();
    for (int i = 0; i < len; i++) {
        best temp;
        temp.name = gnr[i];
        temp.np = gnum[i];
        vector<mysongs> gnr_song = getsongs(genres,plays,gnr[i]);
        //장르별로 재생횟수를 구해옵니다.
        temp.songs = gnr_song;
        album_genr_ord.push_back(temp);
    }
    sort(album_genr_ord.begin(), album_genr_ord.end(),comp);
    

    //장르별 2곡씩 추가
    len = album_genr_ord.size();
    for (auto i : album_genr_ord) {
        sort(i.songs.begin(), i.songs.end(),songcomp);
        answer.push_back(i.songs[0].idx);
        if (album_genr_ord.size() >= 2) {
            answer.push_back(i.songs[1].idx);
        }
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
        cout << "NO : " <<endl;
        for (auto i : ret) {
            cout << i << endl;
        }
        
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

bool songcomp(mysongs a, mysongs b) {
    return (a.ptimes > b.ptimes);
}



vector<mysongs> getsongs(vector<string> ori, vector<int> nums, string target) {
    string s = ori[1];
    int len = ori.size();
    mysongs tmp;

    vector<mysongs> gsongs;


    for (int i = 0; i < len; i++) {
        if (ori[i] == target) {
            tmp.ptimes = nums[i];
            tmp.idx = i;
            gsongs.push_back(tmp);
        }
    }


    return gsongs;
}

*/