# HASH - 전화번호 목록

생성일: 2020년 12월 1일 오후 12:16

# 문제

- 문제링크 : [https://programmers.co.kr/learn/courses/30/lessons/42577](https://programmers.co.kr/learn/courses/30/lessons/42577)
- 어떤 번호가 ,다른번호의 접두어가 되는지( 77 → 7767)
- 접두어가 존재하면  True, 아니면 False

### 제한

- phone_book의 길이는 1 이상 1,000,000 이하입니다.
- 각 전화번호의 길이는 1 이상 20 이하입니다

# 풀이

- 완전탐색  :  유일한 입력인 phone_book의 제한이 백만이므로, 2중포문 n^2로 코딩하면 시간제한에 걸릴수도 있음 → 길이순 정렬이 필요 , 왜냐하면 접두어가 되기 위해서는 항상 짧아야하니까
    - phone_book 을 문자열의 길이순으로 정렬하고,
    - 짧은거부터 검색을 시작
    - 모든 문자열의 앞부분에 검색문자열이  존재하는지를 일일이 검사
    - 존재한다면 그대로 리턴하고 끝
    - 근데 생각해보니 완탐으로 풀면 N*N/2 인데 그냥 풀렸다.

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

```
<br>
<br>
<br>

# 해설
- 단순 구현문제이므로, 위에서 문제분석을 읽고 그대로 코드를 옮기면 된다.
- 따라서 이 문제에서는 스니핏 해설이 존재하지 않는다.
- 로컬에서의 테스트를 위해(for Visual Studio && MSVC) 테스트코드가 추가된 버전을 수록함.

```cpp
include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

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
```
