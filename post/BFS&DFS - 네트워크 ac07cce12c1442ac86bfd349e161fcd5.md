# BFS&DFS - 네트워크

생성일: 2020년 12월 8일 오전 11:21

# 문제

- [문제링크](https://programmers.co.kr/learn/courses/30/lessons/43162) : [https://programmers.co.kr/learn/courses/30/lessons/43162](https://programmers.co.kr/learn/courses/30/lessons/43162)

# 풀이

# 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int map[211][211] = { 0, };
bool visited[211] = { false, };

//int map[5][5] = { 0, };
//bool visited[5] = { false, };
struct MyCoordination
{
	int yi;
	int xj;
};

typedef struct MyCoordination codi;

void bfs(int node,int totalv){
	//bfs search
	queue<codi> q;
	codi cur, next;

	visited[node] = true;
	for (int i = 0; i <= totalv; i++) {
		if (visited[i] == false && map[node][i] == 1) {
			next.xj = i;
			next.yi = node;
			q.push(next);
		}
	}

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		visited[cur.yi] = true;
		for (int i = 1; i <= totalv; i++) {
			if ( map[cur.yi][i] == 1 && visited[i] == false ) {
				next.xj = cur.yi;
				next.yi = i;
				q.push(next);
			}
		}

	}

}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	visited[0] = true;//unused 0
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i+1][j+1] = computers[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] != map[j][i]) {
				map[i][j] = 1;
				map[j][i] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			bfs(i,n);
			answer++;
		}
	}

	return answer;
}

int main(void) {
	memset(visited, false, sizeof(visited));
	memset(map, 0, sizeof(map));
	vector<vector<int>> i1 =
		{ {1,1,0}, {1,1,0}, {0,0,1} };
	cout << solution(3, i1) << endl;

	memset(visited, false, sizeof(visited));
	memset(map, 0, sizeof(map));
	vector<vector<int>> i2 =
		{ {1,1,0}, {1,1,1}, {0,1,1} };
	cout << solution(3, i2) << endl;

	memset(visited, false, sizeof(visited));
	memset(map, 0, sizeof(map));
	vector<vector<int>> i3 =
		//{ {1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1} };
		//{ {1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1} };
		{ {1,0,0,1},{0,1,1,0},{0,1,1,0},{1,1,0,1} };
	cout << solution(4, i3) << endl;
	return 0;
}
```

# 해설

```cpp
snipet
```