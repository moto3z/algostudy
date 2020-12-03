# Graph - 가장 먼 노드

생성일: 2020년 12월 3일 오후 3:38

# 문제

- [문제링크](https://programmers.co.kr/learn/courses/30/lessons/49189) : [https://programmers.co.kr/learn/courses/30/lessons/49189](https://programmers.co.kr/learn/courses/30/lessons/49189)
- N개의 노드가 있고
- 1부터 N까지 번호 적혀있다
- 가장 멀리 떨어진 노드의 갯수
    - 최대노드의 길이를 구하고, 동일한 길이에 뭐뭐가 있는지

# 풀이

- 가장 먼 거리에 있는 - BFS
    - 참고로 거리가 중요할때는 BFS (최단거리 등등..)
    - 모든 경우가 필요할 떄는 DFS
- 다른문제들은 구현이 70% 자료구조&알고리즘이 30% 이하라면
- DFS&BFS 문제들은 DFS/BFS 이론을 알고 적용해야 구현도 된다, 구현이 알고리즘에 매우매우 종속적,..(다른 Hash나 Stack같은건 다른알고리즘으로 풀어도 되지만 요친구들은 어려움)

# 코드

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

bool matrix[20010][20010] = { false, };
int dist[20010] = { 0, }; // -1이면 방문하지않음

int solution(int n, vector<vector<int>> edge) {

    memset(dist, -1, sizeof(dist));// -1이면 방문하지않음, 필수
    int answer = 0;
    int maxi = 0;
    queue<int> q;

    int len = edge.size();
    
    for (int i = 0; i < len; i++) {
        int x = edge[i][0];
        int y = edge[i][1];
        matrix[x][y] = true;
        matrix[y][x] = true;
    }
    
    q.push(1);
    dist[1] = 0;//들어가기전에 미리 방문표시를 해두자

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if ((dist[i] == -1) && (matrix[cur][i] == true)) {
                //방문한적이 없는 노드, 연결된곳 검사

                q.push(i);// i 노드를 방문하자
                dist[i] = dist[cur] + 1;

                if (dist[i] > maxi) {
                    maxi = dist[i];
                }
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        if (dist[i] == maxi) {
            answer++;
        }

    }

    return answer;
}
```

# 해설

```cpp
bool matrix[20010][20010] = { false, };
int dist[20010] = { 0, }; // -1이면 방문하지않음
memset(dist, -1, sizeof(dist));// -1이면 방문하지않음, 필수
```

- bool matrix[20010][20010] : 인접매트릭스 방식으로 그래프를 표현한다.
    - 입력으로 주어진 edge를 map 형식으로 변경했다.
    - matrix방식의 단점은 노드의 제곱만큼 matrix의 사이즈가 커지므로 유의
- dist 배열은 BFS 탐색으로 구한 두가지 정보를 포함하는데
    - 시작점으로부터의 거리가 int형으로 저장
    - 방문여부 : 초기화를 -1로  memset진행하므로 방문한적이 없다면 -1을 가지고 있다.

```cpp
//int solution(int n, vector<vector<int>> edge) {
int len = edge.size();
for (int i = 0; i < len; i++) {
    int x = edge[i][0];
    int y = edge[i][1];
    matrix[x][y] = true;
    matrix[y][x] = true;
}

q.push(1); // 시작점이 1
dist[1] = 0;//들어가기전에 미리 방문표시를 해두자

```

- for문 : 입력으로 주어진 간선정보 edge를 for문 돌려 matrix 행렬에 그래프 정보를 변환해 저장한다.
- q.push(1); : 시작점은 1이므로 큐에 미리 넣어준다
- dist[1] = 0;//들어가기전에 미리 방문표시를 해두자

```cpp
while (!q.empty()) {
    int cur = q.front();
    q.pop();

    //////////////////////////////////////
		//BFS 탐색 알고리즘 구현
		//////////////////////////////////////
}

```

- BFS는 queue가 빌때까지 계속 탐색을 돌린다
- !q.empty()  : 큐가 empty해질때까지 계속

```cpp
int cur = q.front();

for (int i = 1; i <= n; i++) {
 	  if ((dist[i] == -1) && (matrix[cur][i] == true)) {
			  //방문한적이 없는 노드, 연결된곳 검사
		    
    }
}
```

- 만약 방문한적이 없는데 연결되어 있다면?
- 큐에다가 추가해서 방문해봐야함

```cpp
q.push(i);// i 노드를 방문하자
dist[i] = dist[cur] + 1;
        if (dist[i] > maxi) {
            maxi = dist[i];
        }
```

- q.push(i) : i번째 노드를 방문하기 위해 큐에 넣어줌
- dist[i] = dist[cur] + 1 : i 번째 노드는 지금보다 한칸 더 멀리에 있는 곳이므로 +1을 해준다
- 이왕 방문해 준 김에 최대값도 찾고 간다

```cpp
while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int i = 1; i <= n; i++) {
        if ((dist[i] == -1) && (matrix[cur][i] == true)) {
            //방문한적이 없는 노드, 연결된곳 검사

            q.push(i);// i 노드를 방문하자
            dist[i] = dist[cur] + 1;

            if (dist[i] > maxi) {
                maxi = dist[i];
            }
        }
    }
}

```

- 정리해보면 BFS탐색은, 그래프의 모든 노드 탐색을 하기 위해서 너비를 우선해서(가까운곳부터 모두 한번씩 방문해가며 탐색하는 방식
- 문제를 풀어낸 순서는
    - cur 이라는 변수에 지금 방문하고 있는 노드번호를 기억하고 pop
    - if(dist,matrix) 두가지 조건을 만족하면
        - dist[i] == -1 :  i 번째 노드는 방문한적이 없는 노드인지?
        - matrix[cur][i] == true : 지금 방문하고 있는 cur노드랑 연결되어있는지 확인하고
    - q.push(i) : i 번째 노드를 방문예약하고(큐에 넣어줌)
    - dist[i] : 거리는 지금보다 +1인데
    - max : 방문한김에 최대값도 찾아보자

# 끝 . 2020-12-03 By DHKim