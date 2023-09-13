# Q&S - 프린터

생성일: 2020년 12월 2일 오후 9:20

# 문제

- [문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42587) : [https://programmers.co.kr/learn/courses/30/lessons/42587](https://programmers.co.kr/learn/courses/30/lessons/42587)
- 내가 프린트한게 몇번째로 출력되는지
    - 프린트는 중요도 순으로 출력되는데
    - 중요도가 나보다 높은게 하나라도 존재하면 나는 대기목록으로 돌아감
    - 결국 가장 중요한게 나올때까지 큐에서 뺀다음에 마지막에 집어넣음

# 풀이

# 코드

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorites,int location) {
    int answer = 0;
    while (1) {
        for(int i =1 ; i<priorites.size() ; i++) {
            if(priorites[0] < priorites[i]) {
                if(location == 0) {
                    location = priorites.size()-1;
                }
                else {
                    location --;
                }

                priorites.push_back(priorites[0]);
                priorites.erase(priorites.begin());
                break;
            }
            else if(i == priorites.size()-1) {
                priorites.erase(priorites.begin());
                answer++;
                if(location == 0) {
                    return answer;
                }
                location--;
            }
        }
        if(priorites.size() == 1) {
            return answer+1;
        }

    }
}
```

# 해설

```cpp
pass..
```